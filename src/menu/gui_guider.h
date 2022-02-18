/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include <lvgl.h>
//#include "guider_fonts.h"

typedef struct
{
	lv_obj_t *home;
	lv_obj_t *home_contMid;
	lv_obj_t *home_contTop;
	lv_obj_t *home_contBottom;
	lv_obj_t *home_imgCenter;
	lv_obj_t *home_labeldate;
	lv_obj_t *home_labeldateOnly;
	lv_obj_t *home_labelTimeOnly;
	lv_obj_t *home_contMenu;
	lv_obj_t *home_imgbtnKeySet;
	lv_obj_t *home_imgbtnKeySet_label;
	lv_obj_t *home_labelKeySet;
	lv_obj_t *home_imgbtnSetup;
	lv_obj_t *home_imgbtnSetup_label;
	lv_obj_t *home_imgbtnCardSetup;
	lv_obj_t *home_imgbtnCardSetup_label;
	lv_obj_t *home_imgbtnWifiSetup;
	lv_obj_t *home_imgbtnWifiSetup_label;
	lv_obj_t *home_labelCard;
	lv_obj_t *home_labelCarSetup;
	lv_obj_t *home_labelSetup;
	lv_obj_t *home_imgwifiConnect;
	lv_obj_t *home_imgConnect;
	lv_obj_t *home_imgSet;
	lv_obj_t *home_imgCard;
	lv_obj_t *home_imgWifi;
	lv_obj_t *home_imgSetup;
	lv_obj_t *keypad;
	lv_obj_t *keypad_btnm0;
	lv_obj_t *setup;
	lv_obj_t *setup_cont0;
	lv_obj_t *setup_btnsetback;
	lv_obj_t *setup_btnsetback_label;
	lv_obj_t *setup_label2;
	lv_obj_t *setup_printer;
	lv_obj_t *setup_img;
	lv_obj_t *setup_cloud;
	lv_obj_t *loader;
	lv_obj_t *loader_cont0;
	lv_obj_t *loader_loadarc;
	lv_obj_t *loader_loadlabel;
	lv_obj_t *saved;
	lv_obj_t *saved_cont0;
	lv_obj_t *saved_btnsavecontinue;
	lv_obj_t *saved_btnsavecontinue_label;
	lv_obj_t *saved_label2;
	lv_obj_t *saved_img1;
	lv_obj_t *alarm;
	lv_obj_t *alarm_cont0;
	lv_obj_t *alarm_label2;
	lv_obj_t *alarm_img1;
	lv_obj_t *wifi_home;
	lv_obj_t *wifi_home_label0;
	lv_obj_t *wifi_home_label0_1;
	lv_obj_t *wifi_home_list2;
	lv_obj_t *wifi_home_list3;	
	lv_obj_t *setup_select_function1_btn;
	lv_obj_t *setup_select_function2_btn;
	lv_obj_t *setup_select_function3_btn;
	lv_obj_t *setup_select_function4_btn;
	lv_obj_t *setup_select_function5_btn;
	lv_obj_t *setup_select_function6_btn;
	lv_obj_t *setup_select_function7_btn;
	lv_obj_t *setup_select_function8_btn;
	lv_obj_t *home_back;
}lv_ui;

void setup_ui(lv_ui *ui);
extern lv_ui guider_ui;
void setup_scr_home(lv_ui *ui);
void setup_scr_keypad(lv_ui *ui);
void setup_scr_setup(lv_ui *ui);
void setup_scr_loader(lv_ui *ui);
void setup_scr_saved(lv_ui *ui);
void setup_scr_alarm(lv_ui *ui);
void setup_scr_wifi_home(lv_ui * ui);
void setup_select_function(lv_ui *ui);

LV_IMG_DECLARE(_wifi64_alpha_29x29);
LV_IMG_DECLARE(_home_live_alpha_208x117);
LV_IMG_DECLARE(_card64_alpha_29x29);
LV_IMG_DECLARE(_btn3_alpha_85x100);
LV_IMG_DECLARE(_btn2_alpha_85x100);
LV_IMG_DECLARE(_ready_alpha_100x100);
LV_IMG_DECLARE(_wifi_alpha_29x19);
LV_IMG_DECLARE(_cloud_alpha_55x40);
LV_IMG_DECLARE(_alarm_alpha_164x140);
LV_IMG_DECLARE(_tel_alpha_21x21);
LV_IMG_DECLARE(_printer2_alpha_60x55);
LV_IMG_DECLARE(_no_internet_alpha_25x25);
LV_IMG_DECLARE(_security64_alpha_29x29);
LV_IMG_DECLARE(_btn4_alpha_85x100);
LV_IMG_DECLARE(_setup_alpha_29x29);
LV_IMG_DECLARE(_btn_bg_1_alpha_85x100);

#ifdef __cplusplus
}
#endif
#endif