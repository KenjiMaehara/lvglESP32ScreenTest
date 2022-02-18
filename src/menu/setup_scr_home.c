
#include <lvgl.h>
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"


void setup_scr_home(lv_ui *ui){

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
	lv_obj_set_size(ui->home_contTop, 480, 60);
	lv_obj_set_click(ui->home_contTop, false);
	lv_cont_set_layout(ui->home_contTop, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_contTop, LV_FIT_NONE);

	//Write codes home_contBottom
	ui->home_contBottom = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for home_contBottom
	static lv_style_t style_home_contBottom_main;
	lv_style_init(&style_home_contBottom_main);

	//Write style state: LV_STATE_DEFAULT for style_home_contBottom_main
	lv_style_set_radius(&style_home_contBottom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_contBottom_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_color(&style_home_contBottom_main, LV_STATE_DEFAULT, lv_color_make(0x2f, 0x32, 0x43));
	lv_style_set_bg_grad_dir(&style_home_contBottom_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_contBottom_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_contBottom_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_home_contBottom_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_contBottom_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_home_contBottom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_contBottom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_contBottom_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_contBottom_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_contBottom, LV_CONT_PART_MAIN, &style_home_contBottom_main);
	lv_obj_set_pos(ui->home_contBottom, 0, 260);
	lv_obj_set_size(ui->home_contBottom, 480, 60);
	lv_obj_set_click(ui->home_contBottom, false);
	lv_cont_set_layout(ui->home_contBottom, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_contBottom, LV_FIT_NONE);

	//Write codes home_imgCenter
	ui->home_imgCenter = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgCenter
	static lv_style_t style_home_imgCenter_main;
	lv_style_init(&style_home_imgCenter_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgCenter_main
	lv_style_set_image_recolor(&style_home_imgCenter_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgCenter_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgCenter_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgCenter, LV_IMG_PART_MAIN, &style_home_imgCenter_main);
	lv_obj_set_pos(ui->home_imgCenter, 130, 70);
	lv_obj_set_size(ui->home_imgCenter, 208, 117);
	lv_obj_set_click(ui->home_imgCenter, true);
	lv_img_set_src(ui->home_imgCenter,&_home_live_alpha_208x117);
	lv_img_set_pivot(ui->home_imgCenter, 0,0);
	lv_img_set_angle(ui->home_imgCenter, 0);

	//Write codes home_labeldate
	ui->home_labeldate = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labeldate, "20 Nov 2020 08:08");
	lv_label_set_long_mode(ui->home_labeldate, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labeldate, LV_LABEL_ALIGN_CENTER);

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
	lv_style_set_text_font(&style_home_labeldate_main, LV_STATE_DEFAULT, &shin_comic18);
	lv_style_set_text_letter_space(&style_home_labeldate_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labeldate_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labeldate, LV_LABEL_PART_MAIN, &style_home_labeldate_main);
	lv_obj_set_pos(ui->home_labeldate, 240, 20);
	lv_obj_set_size(ui->home_labeldate, 225, 0);

	//Write codes home_contMenu
	ui->home_contMenu = lv_cont_create(ui->home, NULL);

	//Write style LV_CONT_PART_MAIN for home_contMenu
	static lv_style_t style_home_contMenu_main;
	lv_style_init(&style_home_contMenu_main);

	//Write style state: LV_STATE_DEFAULT for style_home_contMenu_main
	lv_style_set_radius(&style_home_contMenu_main, LV_STATE_DEFAULT, 10);
	lv_style_set_bg_color(&style_home_contMenu_main, LV_STATE_DEFAULT, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_color(&style_home_contMenu_main, LV_STATE_DEFAULT, lv_color_make(0xf6, 0xfa, 0xff));
	lv_style_set_bg_grad_dir(&style_home_contMenu_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_contMenu_main, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_home_contMenu_main, LV_STATE_DEFAULT, lv_color_make(0x99, 0x99, 0x99));
	lv_style_set_border_width(&style_home_contMenu_main, LV_STATE_DEFAULT, 1);
	lv_style_set_border_opa(&style_home_contMenu_main, LV_STATE_DEFAULT, 255);
	lv_style_set_pad_left(&style_home_contMenu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_contMenu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_contMenu_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_contMenu_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_contMenu, LV_CONT_PART_MAIN, &style_home_contMenu_main);
	lv_obj_set_pos(ui->home_contMenu, 41, 190);
	lv_obj_set_size(ui->home_contMenu, 380, 120);
	lv_obj_set_click(ui->home_contMenu, false);
	lv_cont_set_layout(ui->home_contMenu, LV_LAYOUT_OFF);
	lv_cont_set_fit(ui->home_contMenu, LV_FIT_NONE);

	//Write codes home_imgbtnKeySet
	ui->home_imgbtnKeySet = lv_imgbtn_create(ui->home, NULL);

	//Write style LV_IMGBTN_PART_MAIN for home_imgbtnKeySet
	static lv_style_t style_home_imgbtnKeySet_main;
	lv_style_init(&style_home_imgbtnKeySet_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnKeySet_main
	lv_style_set_text_color(&style_home_imgbtnKeySet_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_home_imgbtnKeySet_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgbtnKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgbtnKeySet_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnKeySet_main
	lv_style_set_text_color(&style_home_imgbtnKeySet_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnKeySet_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnKeySet_main, LV_STATE_PRESSED, 0);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnKeySet_main
	lv_style_set_text_color(&style_home_imgbtnKeySet_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnKeySet_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnKeySet_main, LV_STATE_CHECKED, 0);
	lv_obj_add_style(ui->home_imgbtnKeySet, LV_IMGBTN_PART_MAIN, &style_home_imgbtnKeySet_main);
	lv_obj_set_pos(ui->home_imgbtnKeySet, 47, 204);
	lv_obj_set_size(ui->home_imgbtnKeySet, 85, 100);
	lv_imgbtn_set_src(ui->home_imgbtnKeySet,LV_BTN_STATE_RELEASED,&_btn_bg_1_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnKeySet,LV_BTN_STATE_PRESSED,&_btn_bg_1_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnKeySet,LV_BTN_STATE_CHECKED_RELEASED,&_btn_bg_1_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnKeySet,LV_BTN_STATE_CHECKED_PRESSED,&_btn_bg_1_alpha_85x100);

	//Write codes home_labelKeySet
	ui->home_labelKeySet = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labelKeySet, "警備");
	lv_label_set_long_mode(ui->home_labelKeySet, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labelKeySet, LV_LABEL_ALIGN_CENTER);

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
	lv_style_set_text_font(&style_home_labelKeySet_main, LV_STATE_DEFAULT, &shin_comic16);
	lv_style_set_text_letter_space(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelKeySet_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelKeySet, LV_LABEL_PART_MAIN, &style_home_labelKeySet_main);
	lv_obj_set_pos(ui->home_labelKeySet, 50, 271);
	lv_obj_set_size(ui->home_labelKeySet, 85, 0);

	//Write codes home_imgbtnSetup
	ui->home_imgbtnSetup = lv_imgbtn_create(ui->home, NULL);

	//Write style LV_IMGBTN_PART_MAIN for home_imgbtnSetup
	static lv_style_t style_home_imgbtnSetup_main;
	lv_style_init(&style_home_imgbtnSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnSetup_main
	lv_style_set_text_color(&style_home_imgbtnSetup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_home_imgbtnSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgbtnSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgbtnSetup_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnSetup_main
	lv_style_set_text_color(&style_home_imgbtnSetup_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnSetup_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnSetup_main, LV_STATE_PRESSED, 0);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnSetup_main
	lv_style_set_text_color(&style_home_imgbtnSetup_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnSetup_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnSetup_main, LV_STATE_CHECKED, 0);
	lv_obj_add_style(ui->home_imgbtnSetup, LV_IMGBTN_PART_MAIN, &style_home_imgbtnSetup_main);
	lv_obj_set_pos(ui->home_imgbtnSetup, 330, 204);
	lv_obj_set_size(ui->home_imgbtnSetup, 85, 100);
	lv_imgbtn_set_src(ui->home_imgbtnSetup,LV_BTN_STATE_RELEASED,&_btn4_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnSetup,LV_BTN_STATE_PRESSED,&_btn4_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnSetup,LV_BTN_STATE_CHECKED_RELEASED,&_btn4_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnSetup,LV_BTN_STATE_CHECKED_PRESSED,&_btn4_alpha_85x100);

	//Write codes home_imgbtnCardSetup
	ui->home_imgbtnCardSetup = lv_imgbtn_create(ui->home, NULL);

	//Write style LV_IMGBTN_PART_MAIN for home_imgbtnCardSetup
	static lv_style_t style_home_imgbtnCardSetup_main;
	lv_style_init(&style_home_imgbtnCardSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnCardSetup_main
	lv_style_set_text_color(&style_home_imgbtnCardSetup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_home_imgbtnCardSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgbtnCardSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgbtnCardSetup_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnCardSetup_main
	lv_style_set_text_color(&style_home_imgbtnCardSetup_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnCardSetup_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnCardSetup_main, LV_STATE_PRESSED, 0);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnCardSetup_main
	lv_style_set_text_color(&style_home_imgbtnCardSetup_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnCardSetup_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnCardSetup_main, LV_STATE_CHECKED, 0);
	lv_obj_add_style(ui->home_imgbtnCardSetup, LV_IMGBTN_PART_MAIN, &style_home_imgbtnCardSetup_main);
	lv_obj_set_pos(ui->home_imgbtnCardSetup, 145, 204);
	lv_obj_set_size(ui->home_imgbtnCardSetup, 85, 100);
	lv_imgbtn_set_src(ui->home_imgbtnCardSetup,LV_BTN_STATE_RELEASED,&_btn2_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnCardSetup,LV_BTN_STATE_PRESSED,&_btn2_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnCardSetup,LV_BTN_STATE_CHECKED_RELEASED,&_btn2_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnCardSetup,LV_BTN_STATE_CHECKED_PRESSED,&_btn2_alpha_85x100);

	//Write codes home_imgbtnWifiSetup
	ui->home_imgbtnWifiSetup = lv_imgbtn_create(ui->home, NULL);

	//Write style LV_IMGBTN_PART_MAIN for home_imgbtnWifiSetup
	static lv_style_t style_home_imgbtnWifiSetup_main;
	lv_style_init(&style_home_imgbtnWifiSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgbtnWifiSetup_main
	lv_style_set_text_color(&style_home_imgbtnWifiSetup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor(&style_home_imgbtnWifiSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgbtnWifiSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgbtnWifiSetup_main, LV_STATE_DEFAULT, 255);

	//Write style state: LV_STATE_PRESSED for style_home_imgbtnWifiSetup_main
	lv_style_set_text_color(&style_home_imgbtnWifiSetup_main, LV_STATE_PRESSED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnWifiSetup_main, LV_STATE_PRESSED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnWifiSetup_main, LV_STATE_PRESSED, 0);

	//Write style state: LV_STATE_CHECKED for style_home_imgbtnWifiSetup_main
	lv_style_set_text_color(&style_home_imgbtnWifiSetup_main, LV_STATE_CHECKED, lv_color_make(0xFF, 0x33, 0xFF));
	lv_style_set_image_recolor(&style_home_imgbtnWifiSetup_main, LV_STATE_CHECKED, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_image_recolor_opa(&style_home_imgbtnWifiSetup_main, LV_STATE_CHECKED, 0);
	lv_obj_add_style(ui->home_imgbtnWifiSetup, LV_IMGBTN_PART_MAIN, &style_home_imgbtnWifiSetup_main);
	lv_obj_set_pos(ui->home_imgbtnWifiSetup, 235, 204);
	lv_obj_set_size(ui->home_imgbtnWifiSetup, 85, 100);
	lv_imgbtn_set_src(ui->home_imgbtnWifiSetup,LV_BTN_STATE_RELEASED,&_btn3_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnWifiSetup,LV_BTN_STATE_PRESSED,&_btn3_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnWifiSetup,LV_BTN_STATE_CHECKED_RELEASED,&_btn3_alpha_85x100);
	lv_imgbtn_set_src(ui->home_imgbtnWifiSetup,LV_BTN_STATE_CHECKED_PRESSED,&_btn3_alpha_85x100);

	//Write codes home_labelCard
	ui->home_labelCard = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labelCard, "登録");
	lv_label_set_long_mode(ui->home_labelCard, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labelCard, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_labelCard
	static lv_style_t style_home_labelCard_main;
	lv_style_init(&style_home_labelCard_main);

	//Write style state: LV_STATE_DEFAULT for style_home_labelCard_main
	lv_style_set_radius(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labelCard_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelCard_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelCard_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_labelCard_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_labelCard_main, LV_STATE_DEFAULT, &shin_comic16);
	lv_style_set_text_letter_space(&style_home_labelCard_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelCard_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelCard, LV_LABEL_PART_MAIN, &style_home_labelCard_main);
	lv_obj_set_pos(ui->home_labelCard, 159, 269);
	lv_obj_set_size(ui->home_labelCard, 60, 0);

	//Write codes home_labelCarSetup
	ui->home_labelCarSetup = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labelCarSetup, "WIFI");
	lv_label_set_long_mode(ui->home_labelCarSetup, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labelCarSetup, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_labelCarSetup
	static lv_style_t style_home_labelCarSetup_main;
	lv_style_init(&style_home_labelCarSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_labelCarSetup_main
	lv_style_set_radius(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, &shin_comic16);
	lv_style_set_text_letter_space(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelCarSetup_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelCarSetup, LV_LABEL_PART_MAIN, &style_home_labelCarSetup_main);
	lv_obj_set_pos(ui->home_labelCarSetup, 239, 268);
	lv_obj_set_size(ui->home_labelCarSetup, 70, 0);

	//Write codes home_labelSetup
	ui->home_labelSetup = lv_label_create(ui->home, NULL);
	lv_label_set_text(ui->home_labelSetup, "設定");
	lv_label_set_long_mode(ui->home_labelSetup, LV_LABEL_LONG_BREAK);
	lv_label_set_align(ui->home_labelSetup, LV_LABEL_ALIGN_CENTER);

	//Write style LV_LABEL_PART_MAIN for home_labelSetup
	static lv_style_t style_home_labelSetup_main;
	lv_style_init(&style_home_labelSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_labelSetup_main
	lv_style_set_radius(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_bg_color(&style_home_labelSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_home_labelSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_home_labelSetup_main, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_text_color(&style_home_labelSetup_main, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_home_labelSetup_main, LV_STATE_DEFAULT, &shin_comic16);
	lv_style_set_text_letter_space(&style_home_labelSetup_main, LV_STATE_DEFAULT, 2);
	lv_style_set_pad_left(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_right(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_top(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_pad_bottom(&style_home_labelSetup_main, LV_STATE_DEFAULT, 0);
	lv_obj_add_style(ui->home_labelSetup, LV_LABEL_PART_MAIN, &style_home_labelSetup_main);
	lv_obj_set_pos(ui->home_labelSetup, 331, 268);
	lv_obj_set_size(ui->home_labelSetup, 75, 0);

	//Write codes home_imgwifiConnect
	ui->home_imgwifiConnect = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgwifiConnect
	static lv_style_t style_home_imgwifiConnect_main;
	lv_style_init(&style_home_imgwifiConnect_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgwifiConnect_main
	lv_style_set_image_recolor(&style_home_imgwifiConnect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgwifiConnect_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgwifiConnect_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgwifiConnect, LV_IMG_PART_MAIN, &style_home_imgwifiConnect_main);
	lv_obj_set_pos(ui->home_imgwifiConnect, 56, 20);
	lv_obj_set_size(ui->home_imgwifiConnect, 29, 19);
	lv_obj_set_click(ui->home_imgwifiConnect, true);
	lv_img_set_src(ui->home_imgwifiConnect,&_wifi_alpha_29x19);
	lv_img_set_pivot(ui->home_imgwifiConnect, 0,0);
	lv_img_set_angle(ui->home_imgwifiConnect, 0);

	//Write codes home_imgConnect
	ui->home_imgConnect = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgConnect
	static lv_style_t style_home_imgConnect_main;
	lv_style_init(&style_home_imgConnect_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgConnect_main
	lv_style_set_image_recolor(&style_home_imgConnect_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgConnect_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgConnect_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgConnect, LV_IMG_PART_MAIN, &style_home_imgConnect_main);
	lv_obj_set_pos(ui->home_imgConnect, 105, 20);
	lv_obj_set_size(ui->home_imgConnect, 21, 21);
	lv_obj_set_click(ui->home_imgConnect, true);
	lv_img_set_src(ui->home_imgConnect,&_tel_alpha_21x21);
	lv_img_set_pivot(ui->home_imgConnect, 0,0);
	lv_img_set_angle(ui->home_imgConnect, 0);

	//Write codes home_imgSet
	ui->home_imgSet = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgSet
	static lv_style_t style_home_imgSet_main;
	lv_style_init(&style_home_imgSet_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgSet_main
	lv_style_set_image_recolor(&style_home_imgSet_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgSet_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgSet_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgSet, LV_IMG_PART_MAIN, &style_home_imgSet_main);
	lv_obj_set_pos(ui->home_imgSet, 88, 216);
	lv_obj_set_size(ui->home_imgSet, 29, 29);
	lv_obj_set_click(ui->home_imgSet, true);
	lv_img_set_src(ui->home_imgSet,&_security64_alpha_29x29);
	lv_img_set_pivot(ui->home_imgSet, 0,0);
	lv_img_set_angle(ui->home_imgSet, 0);

	//Write codes home_imgCard
	ui->home_imgCard = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgCard
	static lv_style_t style_home_imgCard_main;
	lv_style_init(&style_home_imgCard_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgCard_main
	lv_style_set_image_recolor(&style_home_imgCard_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgCard_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgCard_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgCard, LV_IMG_PART_MAIN, &style_home_imgCard_main);
	lv_obj_set_pos(ui->home_imgCard, 183, 220);
	lv_obj_set_size(ui->home_imgCard, 29, 29);
	lv_obj_set_click(ui->home_imgCard, true);
	lv_img_set_src(ui->home_imgCard,&_card64_alpha_29x29);
	lv_img_set_pivot(ui->home_imgCard, 0,0);
	lv_img_set_angle(ui->home_imgCard, 0);

	//Write codes home_imgWifi
	ui->home_imgWifi = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgWifi
	static lv_style_t style_home_imgWifi_main;
	lv_style_init(&style_home_imgWifi_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgWifi_main
	lv_style_set_image_recolor(&style_home_imgWifi_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgWifi_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgWifi_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgWifi, LV_IMG_PART_MAIN, &style_home_imgWifi_main);
	lv_obj_set_pos(ui->home_imgWifi, 269, 217);
	lv_obj_set_size(ui->home_imgWifi, 29, 29);
	lv_obj_set_click(ui->home_imgWifi, true);
	lv_img_set_src(ui->home_imgWifi,&_wifi64_alpha_29x29);
	lv_img_set_pivot(ui->home_imgWifi, 0,0);
	lv_img_set_angle(ui->home_imgWifi, 0);

	//Write codes home_imgSetup
	ui->home_imgSetup = lv_img_create(ui->home, NULL);

	//Write style LV_IMG_PART_MAIN for home_imgSetup
	static lv_style_t style_home_imgSetup_main;
	lv_style_init(&style_home_imgSetup_main);

	//Write style state: LV_STATE_DEFAULT for style_home_imgSetup_main
	lv_style_set_image_recolor(&style_home_imgSetup_main, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_image_recolor_opa(&style_home_imgSetup_main, LV_STATE_DEFAULT, 0);
	lv_style_set_image_opa(&style_home_imgSetup_main, LV_STATE_DEFAULT, 255);
	lv_obj_add_style(ui->home_imgSetup, LV_IMG_PART_MAIN, &style_home_imgSetup_main);
	lv_obj_set_pos(ui->home_imgSetup, 363, 213);
	lv_obj_set_size(ui->home_imgSetup, 29, 29);
	lv_obj_set_click(ui->home_imgSetup, true);
	lv_img_set_src(ui->home_imgSetup,&_setup_alpha_29x29);
	lv_img_set_pivot(ui->home_imgSetup, 0,0);
	lv_img_set_angle(ui->home_imgSetup, 0);

	//Init events for screen
	events_init_home(ui);
}