
#include <lvgl.h>
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_alarm(lv_ui *ui){

	//Write codes alarm
	ui->alarm = lv_obj_create(NULL, NULL);

	//Write codes alarm_cont0
	ui->alarm_cont0 = lv_cont_create(ui->alarm, NULL);

	//Write style LV_CONT_PART_MAIN for alarm_cont0
	static lv_style_t style_alarm_cont0_main;
	lv_style_init(&style_alarm_cont0_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_cont0_main
	lv_style_set_radius(&style_alarm_cont0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_alarm_cont0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_color(&style_alarm_cont0_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_alarm_cont0_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alarm_cont0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_alarm_cont0_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_alarm_cont0_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_alarm_cont0_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_alarm_cont0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_alarm_cont0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_alarm_cont0_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_alarm_cont0_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->alarm_cont0, LV_CONT_PART_MAIN, &style_alarm_cont0_main);
	lv_obj_set_pos(ui->alarm_cont0, 0, 0);
	lv_obj_set_size(ui->alarm_cont0, 480, 319);
	lv_obj_set_click(ui->alarm_cont0, false);
	lv_cont_set_layout(ui->alarm_cont0, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->alarm_cont0, LV_FIT_NONE);

	//Write codes alarm_label2
	ui->alarm_label2 = lv_label_create(ui->alarm, NULL);
	lv_label_set_text(ui->alarm_label2, "異常発生");
	lv_label_set_long_mode(ui->alarm_label2, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->alarm_label2, LV_LABEL_ALIGN_LEFT);

	//Write style LV_LABEL_PART_MAIN for alarm_label2
	static lv_style_t style_alarm_label2_main;
	lv_style_init(&style_alarm_label2_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_label2_main
	lv_style_set_radius(&style_alarm_label2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_alarm_label2_main, LV_STATE_DEFAULT, lv_color_make(0x0a, 0x0a, 0x0a));
	lv_style_set_bg_grad_color(&style_alarm_label2_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_bg_grad_dir(&style_alarm_label2_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_alarm_label2_main, LV_STATE_DEFAULT, 255);
	lv_style_set_text_color(&style_alarm_label2_main, LV_STATE_DEFAULT, lv_color_make(0xfa, 0x00, 0x00));
	lv_style_set_text_font(&style_alarm_label2_main, LV_STATE_DEFAULT, &lv_font_montserrat_32);
	lv_style_set_text_letter_space(&style_alarm_label2_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_alarm_label2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_alarm_label2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_alarm_label2_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_alarm_label2_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->alarm_label2, LV_LABEL_PART_MAIN, &style_alarm_label2_main);
	lv_obj_set_pos(ui->alarm_label2, 161, 230);
	lv_obj_set_size(ui->alarm_label2, 180, 0);
	lv_anim_path_t lv_anim_path_alarm_img1 = {.cb = lv_anim_path_bounce};

	//Write codes alarm_img1
	ui->alarm_img1 = lv_img_create(ui->alarm, NULL);

	//Write style LV_IMG_PART_MAIN for alarm_img1
	static lv_style_t style_alarm_img1_main;
	lv_style_init(&style_alarm_img1_main);

	//Write style state: LV_STATE_DEFAULT for style_alarm_img1_main
	lv_style_set_image_recolor(&style_alarm_img1_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_alarm_img1_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_alarm_img1_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->alarm_img1, LV_IMG_PART_MAIN, &style_alarm_img1_main);
	lv_obj_set_pos(ui->alarm_img1, 155, 65);
	lv_obj_set_size(ui->alarm_img1, 164, 140);
	lv_obj_set_click(ui->alarm_img1, true);

	//Write animation: alarm_img1move in x direction
	lv_anim_t alarm_img1_x;
	lv_anim_init(&alarm_img1_x);
	lv_anim_set_var(&alarm_img1_x, ui->alarm_img1);
	lv_anim_set_time(&alarm_img1_x, 500);
	lv_anim_set_exec_cb(&alarm_img1_x, (lv_anim_exec_xcb_t)lv_obj_set_x);
	lv_anim_set_values(&alarm_img1_x, lv_obj_get_x(ui->alarm_img1), 0);
	_lv_memcpy_small(&alarm_img1_x.path, &lv_anim_path_alarm_img1, sizeof(lv_anim_path_cb_t));
	lv_anim_start(&alarm_img1_x);

	//Write animation: alarm_img1move in y direction
	lv_anim_t alarm_img1_y;
	lv_anim_init(&alarm_img1_y);
	lv_anim_set_var(&alarm_img1_y, ui->alarm_img1);
	lv_anim_set_time(&alarm_img1_y, 500);
	lv_anim_set_exec_cb(&alarm_img1_y, (lv_anim_exec_xcb_t)lv_obj_set_y);
	lv_anim_set_values(&alarm_img1_y, lv_obj_get_y(ui->alarm_img1), 0);
	_lv_memcpy_small(&alarm_img1_y.path, &lv_anim_path_alarm_img1, sizeof(lv_anim_path_cb_t));
	lv_anim_start(&alarm_img1_y);

	lv_img_set_src(ui->alarm_img1,&_alarm_alpha_164x140);
	lv_img_set_pivot(ui->alarm_img1, 0,0);
	lv_img_set_angle(ui->alarm_img1, 0);
}