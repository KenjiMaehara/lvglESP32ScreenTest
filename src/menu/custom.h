// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/*
 * custom.h
 *
 *  Created on: July 29, 2020
 *      Author: nxf53801
 */

#ifndef __CUSTOM_H_
#define __CUSTOM_H_


#ifdef __cplusplus
extern "C" {
#endif
#include "gui_guider.h"

enum SCR_ID {
	SCR_HOME = 0,
	SCR_SETUP = 1,
	SCR_LOADER = 2,
	SCR_SAVED = 3,
	SCR_KEYPAD=4,
	SCR_ALARM=5,
	SCR_WIFI_HOME = 6,
	SCR_TIME_SHOW = 7,
	SCR_AREA = 8
};

extern int cur_scr;
extern lv_anim_t ani_en_btn_click;

void home_event_init(void);
void setup_event_init(void);
void loader_event_init(void);
void saved_event_init(void);
void keypad_event_init(void);
void alarm_event_init(void);
void wifi_home_event_init(void);
void event_cb(void);

void custom_init(lv_ui *ui);
void guider_load_screen(int scr_id);
void lv_menu_anim_in_all(lv_obj_t * obj, uint32_t delay);
void add_loader(void (*end_cb)(lv_anim_t *));
void load_keypad(lv_anim_t *a);
void load_wifi_home(lv_anim_t *a);
void load_area(lv_anim_t *a);
void update_time(char * date);

extern void setup_time_function(lv_ui *ui);
extern void update_onlyData(char * date);
extern void update_onlyTime(char * date);

extern void setup_scr_area(lv_ui *ui);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* __CUSTOM_H_ */
