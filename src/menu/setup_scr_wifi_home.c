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


void setup_scr_wifi_home(lv_ui *ui){

	//Write codes wifi_home
	ui->wifi_home = lv_obj_create(NULL, NULL);

	//Write codes wifi_home_label0
	ui->wifi_home_label0 = lv_label_create(ui->wifi_home, NULL);
	lv_label_set_text(ui->wifi_home_label0, "<");
	lv_label_set_long_mode(ui->wifi_home_label0, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->wifi_home_label0, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for wifi_home_label0
	static lv_style_t style_wifi_home_label0_main;
	lv_style_init(&style_wifi_home_label0_main);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_label0_main
	lv_style_set_radius(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_wifi_home_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_label0_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_label0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_wifi_home_label0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_home_label0_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_wifi_home_label0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->wifi_home_label0, LV_LABEL_PART_MAIN, &style_wifi_home_label0_main);
	lv_obj_set_pos(ui->wifi_home_label0, 19, 7);
	lv_obj_set_size(ui->wifi_home_label0, 42, 0);

	//Write codes wifi_home_label0_1
	ui->wifi_home_label0_1 = lv_label_create(ui->wifi_home, NULL);
	lv_label_set_text(ui->wifi_home_label0_1, "WiFi");
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
	lv_style_set_bg_opa(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, &lv_font_montserrat_24);
	lv_style_set_text_letter_space(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_wifi_home_label0_1_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->wifi_home_label0_1, LV_LABEL_PART_MAIN, &style_wifi_home_label0_1_main);
	lv_obj_set_pos(ui->wifi_home_label0_1, 69, 10);
	lv_obj_set_size(ui->wifi_home_label0_1, 406, 0);

	//Write codes wifi_home_list2
	ui->wifi_home_list2 = lv_list_create(ui->wifi_home, NULL);
	lv_list_set_edge_flash(ui->wifi_home_list2, true);
	lv_list_set_anim_time(ui->wifi_home_list2, 255);

	//Write style LV_LIST_PART_BG for wifi_home_list2
	static lv_style_t style_wifi_home_list2_bg;
	lv_style_init(&style_wifi_home_list2_bg);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list2_bg
	lv_style_set_radius(&style_wifi_home_list2_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_wifi_home_list2_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_wifi_home_list2_bg, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->wifi_home_list2, LV_LIST_PART_BG, &style_wifi_home_list2_bg);

	//Write style LV_LIST_PART_SCROLLABLE for wifi_home_list2
	static lv_style_t style_wifi_home_list2_scrollable;
	lv_style_init(&style_wifi_home_list2_scrollable);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list2_scrollable
	lv_style_set_radius(&style_wifi_home_list2_scrollable, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_wifi_home_list2_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_list2_scrollable, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_list2_scrollable, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_list2_scrollable, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->wifi_home_list2, LV_LIST_PART_SCROLLABLE, &style_wifi_home_list2_scrollable);

	//Write style LV_BTN_PART_MAIN for wifi_home_list2
	static lv_style_t style_wifi_home_list2_main_child;
	lv_style_init(&style_wifi_home_list2_main_child);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list2_main_child
	lv_style_set_radius(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_wifi_home_list2_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->wifi_home_list2, 23, 62);
	lv_obj_set_size(ui->wifi_home_list2, 437, 47);
	lv_obj_t *wifi_home_list2_btn;
	wifi_home_list2_btn = lv_list_add_btn(ui->wifi_home_list2, LV_SYMBOL_WIFI, "");
	lv_obj_add_style(wifi_home_list2_btn, LV_BTN_PART_MAIN, &style_wifi_home_list2_main_child);

	//Write codes wifi_home_list3
	ui->wifi_home_list3 = lv_list_create(ui->wifi_home, NULL);
	lv_list_set_edge_flash(ui->wifi_home_list3, true);
	lv_list_set_anim_time(ui->wifi_home_list3, 255);

	//Write style LV_LIST_PART_BG for wifi_home_list3
	static lv_style_t style_wifi_home_list3_bg;
	lv_style_init(&style_wifi_home_list3_bg);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list3_bg
	lv_style_set_radius(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, 3);
	lv_style_set_border_color(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, lv_color_make(0xe1, 0xe6, 0xee));
	lv_style_set_border_width(&style_wifi_home_list3_bg, LV_STATE_DEFAULT, 1);
	lv_obj_add_style(ui->wifi_home_list3, LV_LIST_PART_BG, &style_wifi_home_list3_bg);

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

	//Write style LV_BTN_PART_MAIN for wifi_home_list3
	static lv_style_t style_wifi_home_list3_main_child;
	lv_style_init(&style_wifi_home_list3_main_child);

	//Write style state: LV_STATE_DEFAULT for style_wifi_home_list3_main_child
	lv_style_set_radius(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, 3);
	lv_style_set_bg_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_wifi_home_list3_main_child, LV_STATE_DEFAULT, lv_color_make(0x0D, 0x30, 0x55));
	lv_obj_set_pos(ui->wifi_home_list3, 20, 141);
	lv_obj_set_size(ui->wifi_home_list3, 436, 162);

	lv_obj_t *wifi_home_list3_btn;

	wifi_home_list3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_WIFI, "元へ戻る");
	lv_obj_add_style(wifi_home_list3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

	wifi_home_list3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_FILE, "New");
	lv_obj_add_style(wifi_home_list3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

	wifi_home_list3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_DIRECTORY, "Open");
	lv_obj_add_style(wifi_home_list3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

	wifi_home_list3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_CLOSE, "Delete");
	lv_obj_add_style(wifi_home_list3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

	wifi_home_list3_btn = lv_list_add_btn(ui->wifi_home_list3, LV_SYMBOL_EDIT, "Edit");
	lv_obj_add_style(wifi_home_list3_btn, LV_BTN_PART_MAIN, &style_wifi_home_list3_main_child);
	lv_obj_set_event_cb(wifi_home_list3_btn, event_handler);

}

static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	char *s1 = "元へ戻る";
	char *s2 = "New";
	char *s3 = "Open";
	char *s4 = "Delete";

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
		
		
    }
}