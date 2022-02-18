/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include <lvgl.h>
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


static void event_handler(lv_obj_t * obj, lv_event_t event);


void setup_wifiScan_function1(lv_ui *ui){

	//Write codes wifi_home
	ui->wifi_home = lv_obj_create(NULL, NULL);



	//Screen back
    ui->home_labelKeySet = lv_btn_create(ui->wifi_home, NULL);
    lv_obj_set_event_cb(ui->home_labelKeySet, event_handler);
    lv_obj_align(ui->home_labelKeySet, NULL, LV_ALIGN_CENTER, 0, -40);
	lv_obj_set_style_local_bg_color(ui->home_labelKeySet,LV_OBJ_PART_MAIN ,LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0));
	lv_obj_set_pos(ui->home_labelKeySet, 19, 10);
	lv_obj_set_size(ui->home_labelKeySet, 80, 50);

	ui->home_labelKeySet = lv_label_create(ui->home_labelKeySet, NULL);
    lv_label_set_text(ui->home_labelKeySet, "<");

	//Write style LV_LABEL_PART_MAIN for home_labelKeySet
	static lv_style_t style_home_labelKeySet_main;
	lv_style_init(&style_home_labelKeySet_main);

	//Write style state: LV_STATE_DEFAULT for style_home_labelKeySet_main
	lv_style_set_radius(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labelKeySet_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelKeySet_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelKeySet_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_labelKeySet_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_labelKeySet_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelKeySet, LV_LABEL_PART_MAIN, &style_home_labelKeySet_main);




	//Home back
    ui->home_labelKeySet = lv_btn_create(ui->wifi_home, NULL);
    lv_obj_set_event_cb(ui->home_labelKeySet, event_handler);
    lv_obj_align(ui->home_labelKeySet, NULL, LV_ALIGN_CENTER, 0, -40);
	lv_obj_set_style_local_bg_color(ui->home_labelKeySet,LV_OBJ_PART_MAIN ,LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0));
	lv_obj_set_pos(ui->home_labelKeySet, 400, 10);
	lv_obj_set_size(ui->home_labelKeySet, 80, 50);

	ui->home_labelKeySet = lv_label_create(ui->home_labelKeySet, NULL);
    lv_label_set_text(ui->home_labelKeySet, "HOME");

	//Write style LV_LABEL_PART_MAIN for home_labelKeySet
	static lv_style_t style_home_labelKeySet_main02;
	lv_style_init(&style_home_labelKeySet_main02);

	//Write style state: LV_STATE_DEFAULT for style_home_labelKeySet_main02
	lv_style_set_radius(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	//lv_style_set_text_font(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelKeySet_main02, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelKeySet, LV_LABEL_PART_MAIN, &style_home_labelKeySet_main02);





	#if 1

	//Write codes wifi_home_label0_1
	ui->wifi_home_label0_1 = lv_label_create(ui->wifi_home, NULL);
	lv_label_set_text(ui->wifi_home_label0_1, "メンテナンスモード");
	lv_label_set_long_mode(ui->wifi_home_label0_1, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->wifi_home_label0_1, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for wifi_home_label0_1
	static lv_style_t style_wifi_home_label0_1_main;
	lv_style_init(&style_wifi_home_label0_1_main);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_label0_1_main
	lv_style_set_radius(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, &shin_comic18);
	lv_style_set_text_letter_space(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->wifi_home_label0_1, LV_LABEL_PART_MAIN, &style_wifi_home_label0_1_main);
	lv_obj_set_pos(ui->wifi_home_label0_1, 139, 20);
	lv_obj_set_size(ui->wifi_home_label0_1, 406, 0);

	#endif



	//Write codes wifi_home_list3
	ui->wifi_home_list3 = lv_list_create(ui->wifi_home, NULL);
	lv_list_set_edge_flash(ui->wifi_home_list3, true);
	lv_list_set_anim_time(ui->wifi_home_list3, 255);

	#if 0
	//Write style LV_LIST_PART_BG for wifi_home_list3
	static lv_style_t style_wifi_home_list3_bg;
	lv_style_init(&style_wifi_home_list3_bg);

	lv_style_set_text_font(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, &shin_comic18);
	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list3_bg
	lv_style_set_radius(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->wifi_home_list3, LV_LIST_PART_BG, &style_wifi_home_list3_bg);
	#endif
	

	#if 0
	//Write style LV_LIST_PART_SCROLLABLE for wifi_home_list3
	static lv_style_t style_wifi_home_list3_scrollable;
	lv_style_init(&style_wifi_home_list3_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list3_scrollable
	lv_style_set_radius(&style_wifi_home_list3_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_wifi_home_list3_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_list3_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_list3_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_list3_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->wifi_home_list3, LV_LIST_PART_SCROLLABLE, &style_wifi_home_list3_scrollable);
	#endif

	//Write style LV_BTN_PART_MAIN for wifi_home_list3
	static lv_style_t style_wifi_home_list3_main_child;
	lv_style_init(&style_wifi_home_list3_main_child);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list3_main_child
	lv_style_set_text_font(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, &shin_comic18);
	lv_style_set_radius(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->wifi_home_list3, 20, 70);
	lv_obj_set_size(ui->wifi_home_list3, 446, 240);




	ui->setup_select_function1_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_DIRECTORY, "ジャーナル記録");
	lv_obj_add_style(ui->setup_select_function1_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

	ui->setup_select_function2_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_FILE, "設定初期化");
	lv_obj_add_style(ui->setup_select_function2_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function2_btn, event_handler);

	ui->setup_select_function3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_DIRECTORY, "ジャーナル記録");
	lv_obj_add_style(ui->setup_select_function3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function3_btn, event_handler);

	ui->setup_select_function4_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_CLOSE, "ジャーナル消去");
	lv_obj_add_style(ui->setup_select_function4_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function4_btn, event_handler);

	ui->setup_select_function5_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_EDIT, "端末機設定");
	lv_obj_add_style(ui->setup_select_function5_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function5_btn, event_handler);

	ui->setup_select_function6_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_EDIT, "送信データ消去");
	lv_obj_add_style(ui->setup_select_function6_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function6_btn, event_handler);

	ui->setup_select_function7_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_EDIT, "カード設定");
	lv_obj_add_style(ui->setup_select_function7_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function7_btn, event_handler);

	ui->setup_select_function8_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_EDIT, "wifi設定");
	lv_obj_add_style(ui->setup_select_function8_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	//lv_obj_set_event_cb(setup_select_function8_btn, event_handler);

	setup_select_function_init(ui);
}



static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	char *s1 = "<";
	char *s2 = "New";
	char *s3 = "Open";
	char *s4 = "Delete";

	//uint16_t id = lv_list_get_size(obj);
	//uint16_t id = 0;

    if(event == LV_EVENT_CLICKED) {
		if (strcmp(lv_list_get_btn_text(obj),s1)==0)
		{
			printf("Clicked:Back HOME\n");
			guider_load_screen(SCR_HOME);
		}
		else if(strcmp(lv_list_get_btn_text(obj),s2)==0)
		{
			printf("Clicked:newnew\n");
		}


		//printf("listId == %d\n",id);		
		
    }
}