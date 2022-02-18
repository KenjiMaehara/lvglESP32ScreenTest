/*
 * Copyright 2021 NXP
 * SPDX-License-Identifier: MIT
 */

#include <lvgl.h>
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


void setup_time_function(lv_ui *ui){

	//Write codes home
	ui->home = lv_obj_create(NULL, NULL);

	//Write codes home_contMid
	ui->home_contMid = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for home_contMid
	static lv_style_t style_home_contMid_main;
	lv_style_init(&style_home_contMid_main);

	//Write style state: LV_STATE_DEFAULT for style_home_contMid_main
	lv_style_set_radius(&style_home_contMid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_contMid_main, LV_STATE_DEFAULT, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_color(&style_home_contMid_main, LV_STATE_DEFAULT, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_dir(&style_home_contMid_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_contMid_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_contMid_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_home_contMid_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_contMid_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_home_contMid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_contMid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_contMid_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_contMid_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_contMid, LV_CONT_PART_MAIN, &style_home_contMid_main);
	lv_obj_set_pos(ui->home_contMid, 0, 60);
	lv_obj_set_size(ui->home_contMid, 480, 200);
	lv_obj_set_click(ui->home_contMid, false);
	lv_cont_set_layout(ui->home_contMid, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_contMid, LV_FIT_NONE);

	//Write codes home_contTop
	ui->home_contTop = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for home_contTop
	static lv_style_t style_home_contTop_main;
	lv_style_init(&style_home_contTop_main);

	//Write style state: LV_STATE_DEFAULT for style_home_contTop_main
	lv_style_set_radius(&style_home_contTop_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_contTop_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_home_contTop_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_home_contTop_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_contTop_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_contTop_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_home_contTop_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_contTop_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_home_contTop_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_contTop_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_contTop_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_contTop_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_contTop, LV_CONT_PART_MAIN, &style_home_contTop_main);
	lv_obj_set_pos(ui->home_contTop, 0, 0);
	lv_obj_set_size(ui->home_contTop, 480, 320);
	lv_obj_set_click(ui->home_contTop, false);
	lv_cont_set_layout(ui->home_contTop, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_contTop, LV_FIT_NONE);



	//Write codes home_labeldate
	ui->home_labeldateOnly = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labeldateOnly, "20 Nov ");
	lv_label_set_long_mode(ui->home_labeldateOnly, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labeldateOnly, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_labeldate
	static lv_style_t style_home_labeldate_date;
	lv_style_init(&style_home_labeldate_date);

	//Write style state: LV_STATE_DEFAULT for style_home_labeldate_date
	lv_style_set_radius(&style_home_labeldate_date, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labeldate_date, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_home_labeldate_date, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_home_labeldate_date, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labeldate_date, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_labeldate_date, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_text_font(&style_home_labeldate_date, LV_STATE_DEFAULT, &shin_comic18);
	lv_style_set_text_font(&style_home_labeldate_date, LV_STATE_DEFAULT, &lv_font_montserrat_38);
	lv_style_set_text_letter_space(&style_home_labeldate_date, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labeldate_date, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labeldate_date, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labeldate_date, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labeldate_date, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labeldateOnly, LV_LABEL_PART_MAIN, &style_home_labeldate_date);
	lv_obj_set_pos(ui->home_labeldateOnly, 110, 50);
	lv_obj_set_size(ui->home_labeldateOnly, 300, 0);



	//Write codes home_labeldate
	ui->home_labelTimeOnly = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labelTimeOnly, "20 Nov ");
	lv_label_set_long_mode(ui->home_labelTimeOnly, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labelTimeOnly, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_labeldate
	static lv_style_t style_home_labeldate_main;
	lv_style_init(&style_home_labeldate_main);

	//Write style state: LV_STATE_DEFAULT for style_home_labeldate_main
	lv_style_set_radius(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labeldate_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_home_labeldate_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_home_labeldate_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labeldate_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_home_labeldate_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	//lv_style_set_text_font(&style_home_labeldate_main, LV_STATE_DEFAULT, &shin_comic18);
	lv_style_set_text_font(&style_home_labeldate_main, LV_STATE_DEFAULT, &lv_font_montserrat_48);
	lv_style_set_text_letter_space(&style_home_labeldate_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelTimeOnly, LV_LABEL_PART_MAIN, &style_home_labeldate_main);
	lv_obj_set_pos(ui->home_labelTimeOnly, 120, 150);
	lv_obj_set_size(ui->home_labelTimeOnly, 225, 0);



}
