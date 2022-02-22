#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_MCP23017.h>
#include <MCP342x.h>
#include "devIO.h"


struct led_dev_t 
{
    Adafruit_MCP23017   mcp;
    uint8_t             addr;
    uint8_t             set_led;
    uint8_t             emg_led;
}; 

led_dev_t led[5];

Adafruit_MCP23017 mcp_sensor_relay;
uint8_t           io_relay;

Adafruit_MCP23017 mcp_interrupt_sys_led;
uint8_t           io_sysled;


MCP342x io_batt_volt_adc_device = MCP342x(0x68);
//static void  IRAM_ATTR InterruptCallBack();

void io_init(void)
{

//  printf("io_initです－０\n");  


    /* I2C-2 pin setting*/
    Wire.begin(25,26);

    /* I2C-2 Clock*/
    Wire.setClock(1000000);  

    // hardware led setting

    memset(led,0,sizeof(led_dev_t) * 5);

  printf("io_initです－１\n");  

    // i2c addr setting; 
    led[0].addr = 0x01;
    led[1].addr = 0x03;
    led[2].addr = 0x04;
    led[3].addr = 0x05;
    led[4].addr = 0x06;

  printf("io_initです－２\n");  

    // io direction setting
    for(int j = 0 ; j < 5 ; j++)
    {
        led[j].mcp.begin(led[j].addr);
        for(int i = 0 ; i < 16 ; i ++)
        {
            if(i < 8)
                led[j].mcp.pinMode(i,INPUT);
            
                led[j].mcp.pinMode(i,OUTPUT);
        }
    }

  printf("io_initです－３\n");  

//#if 0	//処理しない
#if 1	//処理する

    int16_t ledTest = 1;

    for(int i = 0 ; i < 1 ; i++)
    {
        for(int j = 0 ; j < 16 ; j++)
        {
            #if 0
            led[i].mcp.writeGPIOAB(0xffff);
            delay(100);
            led[i].mcp.writeGPIOAB(0x0000);
            delay(100);
            #endif


            ledTest =  ledTest << 1;
            led[i].mcp.writeGPIOAB(ledTest);
            delay(100);

        }
    }




  printf("io_initです－４\n");  

    mcp_sensor_relay.begin(0x02);

  printf("io_initです－５\n");  

    for(int i = 0 ; i < 8 ; i ++)
    {
        mcp_sensor_relay.pinMode(i,INPUT);  // sensor ch
    }    
    mcp_sensor_relay.pinMode(14,INPUT); // TAMPA
    mcp_sensor_relay.pinMode(15,INPUT); // Exit Set/RESET

    for(int i = 0 ; i < 5 ; i ++)
    {
        mcp_sensor_relay.pinMode(i + 8,OUTPUT);  // realy, batt on/off
    }
    io_relay =  0x00;    


    mcp_interrupt_sys_led.begin(0x00);

    for(int i = 0 ; i < 8 ; i ++)
    {
        mcp_interrupt_sys_led.pinMode(i,INPUT);  // interrupt pin
        mcp_interrupt_sys_led.pullUp(i,HIGH);   //pull up
    }    

    for(int i = 0 ; i < 8 ; i ++)
    {
        mcp_interrupt_sys_led.pinMode(i+8,OUTPUT);  // interrupt pin
    }    
    io_sysled =  0x00;    


    pinMode(34,INPUT);    
    //attachInterrupt(digitalPinToInterrupt(34), InterruptCallBack, FALLING);    

#endif

}

bool dfplay_busy(void)
{
    if(mcp_interrupt_sys_led.digitalRead(4) == 0)
        return true;

    return false;
}


#if 0

extern SemaphoreHandle_t xTaskSemaphore ;

static void IRAM_ATTR InterruptCallBack()
{
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    if(xTaskSemaphore != NULL)
        xSemaphoreGiveFromISR( xTaskSemaphore, &xHigherPriorityTaskWoken );
  
}

#endif

/*
    area : 2 ~ 30
*/
void io_led_area_set(uint8_t area,bool set)
{
    int led_dev_id,led_id;
   
    if(area < 2)
        return;

    led_dev_id = ((area - 2) / 8);
    led_id = ((area - 2) % 8);

    if(set == true)
        led[led_dev_id].set_led |= 0x01 << led_id;
    else
        led[led_dev_id].set_led &= ~(0x01 << led_id);

    led[led_dev_id].mcp.digitalWrite(led_id,set);    
}

/*
    area : 2 ~ 30
*/
void io_led_area_emg(uint8_t area,bool set)
{
    int led_dev_id,led_id;
   
    if(area < 2)
        return;

    led_dev_id = ((area - 2) / 8);
    led_id = ((area - 2) % 8);

    if(set == true)
        led[led_dev_id].emg_led |= 0x01 << led_id;
    else
        led[led_dev_id].emg_led &= ~(0x01 << led_id);

    led[led_dev_id].mcp.digitalWrite(led_id + 8,set);    
}

/*
*/
void io_led_area1_ch_set(uint8_t ch,bool set)
{
    if(ch > 7)
        return;

 
    if(set == true)
        led[0].set_led |= 0x01 << ch;
    else
        led[0].set_led &= ~(0x01 << ch);

    led[0].mcp.digitalWrite(ch,set);    
}

/*
*/
void io_led_area1_ch_emg(uint8_t ch,bool set)
{
    if(ch > 7)
        return;

 
    if(set == true)
        led[0].emg_led |= 0x01 << ch;
    else
        led[0].emg_led &= ~(0x01 << ch);

    led[0].mcp.digitalWrite(ch + 8 ,set);    
}

/*
*/
void io_realy_set(uint8_t realy,bool set)
{
    if(realy > 4)
        return;

    mcp_sensor_relay.digitalWrite(realy + 8, set);
 
    if(set == true)
        io_relay |= 0x01 << realy;
    else
        io_relay &= ~(0x01 << realy);

    mcp_sensor_relay.digitalWrite(realy + 8, set);
}

uint8_t io_read_area1_sensor_ch(void)
{
    uint8_t sensor;

    sensor = mcp_sensor_relay.readGPIO(0);
    
    return sensor;
}

uint8_t io_read_tampa(void)
{
    uint8_t tampa;

    tampa = mcp_sensor_relay.digitalRead(15);
    
    return tampa;
}

uint8_t io_read_sr(void)
{
    uint8_t sr;

    sr = mcp_sensor_relay.digitalRead(14);
    
    return sr;
}

void io_batt_onoff(bool onoff)
{
    mcp_sensor_relay.digitalWrite(12,onoff);
}

void io_power_led_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(15,onoff);
}

void io_comm_led_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(14,onoff);
}

void io_comm_err1_led_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(13,onoff);
}

void io_comm_err2_led_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(12,onoff);
}

void io_tamp_led_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(10,onoff);
}

void io_buzzer_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(11,onoff);
}

void io_bl_ctl_onoff(bool onoff)
{
    mcp_interrupt_sys_led.digitalWrite(9,onoff);
}

bool dfplay_mini_busy(void)
{
    if(mcp_interrupt_sys_led.digitalRead(4)==LOW)
        return true;

    return false;
}



// ADCの精度　測定結果       誤差は抵抗値の精度の問題、ADCNo1とNo2を入れ替えても誤差は同じ
// 電圧計(V)  試作機No1(V)  電圧計(V)  試作機No2(V)
//  15.007      15.02       15.002    14.85
//  14.502      14.51       14.506    14.36
//  14.207      14.22       14.200    14.05  BATT･Full → 14.2V Uper
//  14.000      14.01       14.004    13.86
//  13.498      13.51       13.506    13.37
//  13.004      13.01       13.005    12.87
//  12.503      12.51       12.508    12.37
//  12.005      12.01       12.007    11.88   BATT･LOW復旧
//  11.502      11.50       11.502    11.37
//  11.005      11.00       11.000    10.88   BATT･LOW発生
//  10.503      10.50       10.500    10.38
//  10.004      10.00       10.007    9.89
//   9.704       9.69        9.704    9.59   BATT･OFF 9.7V→Under VOLT
//   9.503       9.49        9.506    9.39
//   9.004       8.99        9.005    8.89
//   8.506       8.49        8.500    8.39
//   8.005       7.99
//   7.501       7.48
//   7.007       6.98

float_t io_batt_volt_adc(void)
{
    MCP342x::Config status;
    long value = 0;
    MCP342x::error_t err;

    err = io_batt_volt_adc_device.convertAndRead(MCP342x::channel1,MCP342x::oneShot,MCP342x::resolution16, MCP342x::gain1,1000000, value, status);

    if (err != MCP342x::error_t::errorNone ) 
    {
        return (float_t) 0L;
    }
 
    return (float_t)(value * 2.048 / 32767*8);
 }


