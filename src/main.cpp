#include <Arduino.h>
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <devIO.h>
#include "menu\gui_guider.h"
#include "menu\custom.h"
#include "menu\events_init.h"
#include "SPIFFS.h" // ESP32 SPIFFS 라이브러리
#include <WiFi.h>

//#include <lv_examples.h>

LV_FONT_DECLARE(Japan1);
#define LVGL_TICK_PERIOD 60

//Ticker tick; /* timer for interrupt handler */
TFT_eSPI tft = TFT_eSPI(); /* TFT instance */
static lv_disp_buf_t disp_buf;
static lv_color_t buf[LV_HOR_RES_MAX * 10];

lv_obj_t * slider_label;
int screenWidth = 480;
int screenHeight = 320;
  
#if USE_LV_LOG != 0
/* Serial debugging */
void my_print(lv_log_level_t level, const char * file, uint32_t line, const char * dsc)
{

  Serial.printf("%s@%d->%s\r\n", file, line, dsc);
  delay(100);
}
#endif

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  uint16_t c;

  tft.startWrite(); /* Start new TFT transaction */
  tft.setAddrWindow(area->x1, area->y1, (area->x2 - area->x1 + 1), (area->y2 - area->y1 + 1)); /* set the working window */
  for (int y = area->y1; y <= area->y2; y++) {
    for (int x = area->x1; x <= area->x2; x++) {
      c = color_p->full;
      tft.writeColor(c, 1);
      color_p++;
    }
  }
  tft.endWrite(); /* terminate TFT transaction */
  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

bool my_touchpad_read(lv_indev_drv_t * indev_driver, lv_indev_data_t * data)
{
    uint16_t touchX, touchY;

    bool touched = tft.getTouch(&touchX, &touchY, 600);

    if(!touched)
    {
      return false;
    }

    if(touchX>screenWidth || touchY > screenHeight)
    {
      Serial.println("Y or y outside of expected parameters..");
      Serial.print("y:");
      Serial.print(touchX);
      Serial.print(" x:");
      Serial.print(touchY);
    }
    else
    {

      data->state = touched ? LV_INDEV_STATE_PR : LV_INDEV_STATE_REL; 
  
      /*Save the state and save the pressed coordinate*/
      //if(data->state == LV_INDEV_STATE_PR) touchpad_get_xy(&last_x, &last_y);
     
      /*Set the coordinates (if released use the last pressed coordinates)*/
      data->point.x = touchX;
      data->point.y = touchY;
  
   //   Serial.print("Data x");
   //   Serial.println(touchX);
      
   //   Serial.print("Data y");
   //   Serial.println(touchY);

    }

    return false; /*Return `false` because we are not buffering and no more data to read*/
}

lv_ui guider_ui;
//void wifi_scan();

void setup() {

  printf("1@1@1@1@1@\n");  


  ledcSetup(10, 5000/*freq*/, 10 /*resolution*/);
  ledcAttachPin(32, 10);
  analogReadResolution(10);
  ledcWrite(10,768);

  Serial.begin(115200); /* prepare for possible serial debug */

  lv_init();

  #if USE_LV_LOG != 0
    lv_log_register_print_cb(my_print); /* register print function for debugging */
  #endif

  tft.begin(); /* TFT init */
#if 0 
  tft.setRotation(3);

  uint16_t calData[5] = { 275, 3620, 264, 3532, 1 };
#else
  tft.setRotation(1);

  //uint16_t calData[5] = { 1, 3532,264,3620,275};
  uint16_t calData[5] = { 231, 3567, 344, 3355, 7 };     // 2021.11.26変更
#endif
  tft.setTouch(calData);

  lv_disp_buf_init(&disp_buf, buf, NULL, LV_HOR_RES_MAX * 10);

  /*Initialize the display*/
  lv_disp_drv_t disp_drv;
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = screenWidth;
  disp_drv.ver_res = screenHeight;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.buffer = &disp_buf;
  lv_disp_drv_register(&disp_drv);

  /*Initialize the input device driver*/
  lv_indev_drv_t indev_drv;
  lv_indev_drv_init(&indev_drv);             /*Descriptor of a input device driver*/
  indev_drv.type = LV_INDEV_TYPE_POINTER;    /*Touch pad is a pointer-like device*/
  indev_drv.read_cb = my_touchpad_read;      /*Set your driver function*/
  lv_indev_drv_register(&indev_drv);         /*Finally register the driver*/

//SPIFFS.begin(true); SPIFFS.format(); Serial.println("Format complete!");

	setup_ui(&guider_ui);

  printf("2@2@2@2@2@\n"); 
  //custom_init(&guider_ui);
  //events_init(&guider_ui);
  io_init();

  printf("3@3@3@3@3@\n");  


  printf("4@4@4@4@4@\n");  



  delay(2000);
 

  //task_init();

  printf("6@6@6@6@6@\n");  

//  printf("3@3@3@3@3@\n");  
  

}



void loop() {

  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}
