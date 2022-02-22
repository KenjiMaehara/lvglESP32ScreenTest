/**
 * @file devIO.h
 *
 */

#ifndef DEV_IO_H
#define DEV_IO_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/
void io_init(void);
float_t io_batt_volt_adc(void);

void io_led_area_emg(uint8_t area,bool set);
extern void io_led_area1_ch_emg(uint8_t ch,bool set);
extern uint8_t io_read_area1_sensor_ch(void);
extern uint8_t io_read_tampa(void);

extern void io_buzzer_onoff(bool onoff);
/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*DEV_IO_H*/
