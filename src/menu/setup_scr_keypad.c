
#include <lvgl.h>
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "custom.h"


static void event_handler(lv_obj_t * obj, lv_event_t event);


void setup_scr_keypad(lv_ui *ui){

	//Write codes keypad
	ui->keypad = lv_obj_create(NULL, NULL);

	lv_obj_set_style_local_bg_color( ui->keypad, LV_OBJ_PART_MAIN, LV_STATE_DEFAULT, LV_COLOR_BLACK );

	//Screen back
    ui->home_labelKeySet = lv_btn_create(ui->keypad, NULL);
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



	//Home back
    ui->home_labelKeySet = lv_btn_create(ui->keypad, NULL);
    lv_obj_set_event_cb(ui->home_labelKeySet, event_handler);
    lv_obj_align(ui->home_labelKeySet, NULL, LV_ALIGN_CENTER, 0, -40);
	lv_obj_set_style_local_bg_color(ui->home_labelKeySet,LV_OBJ_PART_MAIN ,LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0));
	lv_obj_set_pos(ui->home_labelKeySet, 400, 10);
	lv_obj_set_size(ui->home_labelKeySet, 80, 50);

	ui->home_labelKeySet = lv_label_create(ui->home_labelKeySet, NULL);
    lv_label_set_text(ui->home_labelKeySet, "Skip");

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









	//Write codes keypad_btnm0
	ui->keypad_btnm0 = lv_btnmatrix_create(ui->keypad, NULL);
	static const uint8_t *keypad_btnm0_text_map[] = {
	"1","2","3","\n",
	"4","5","6","\n",
	"7","8","9","\n",
	"*","0","#","",
	};
	lv_btnmatrix_set_map(ui->keypad_btnm0, keypad_btnm0_text_map);

	//Write style LV_BTNMATRIX_PART_BG for keypad_btnm0
	static lv_style_t style_keypad_btnm0_bg;
	lv_style_init(&style_keypad_btnm0_bg);

	//Write style state: LV_STATE_DEFAULT for style_keypad_btnm0_bg
	lv_style_set_radius(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_bg_color(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, lv_color_make(0x0e, 0x0a, 0x43));
	lv_style_set_bg_grad_color(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, lv_color_make(0x21, 0x07, 0xe4));
	lv_style_set_border_width(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 1);
	lv_style_set_pad_left(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_right(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_top(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 5);
	lv_style_set_pad_bottom(&style_keypad_btnm0_bg, LV_STATE_DEFAULT, 5);
	lv_obj_add_style(ui->keypad_btnm0, LV_BTNMATRIX_PART_BG, &style_keypad_btnm0_bg);

	//Write style LV_BTNMATRIX_PART_BTN for keypad_btnm0
	static lv_style_t style_keypad_btnm0_btn;
	lv_style_init(&style_keypad_btnm0_btn);

	//Write style state: LV_STATE_DEFAULT for style_keypad_btnm0_btn
	lv_style_set_radius(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, 4);
	lv_style_set_bg_color(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_color(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, lv_color_make(0xff, 0xff, 0xff));
	lv_style_set_bg_grad_dir(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, LV_GRAD_DIR_VER);
	lv_style_set_bg_opa(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, 255);
	lv_style_set_border_color(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, lv_color_make(0xd6, 0xdd, 0xe3));
	lv_style_set_border_width(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, 1);
	lv_style_set_text_color(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, lv_color_make(0x00, 0x00, 0x00));
	lv_style_set_text_font(&style_keypad_btnm0_btn, LV_STATE_DEFAULT, &lv_font_montserrat_24);

	lv_obj_add_style(ui->keypad_btnm0, LV_BTNMATRIX_PART_BTN, &style_keypad_btnm0_btn);
	lv_obj_set_pos(ui->keypad_btnm0, 130, 6);
	lv_obj_set_size(ui->keypad_btnm0, 246, 308);

	//Init events for screen
	events_init_keypad(ui);
}




static void event_handler(lv_obj_t * obj, lv_event_t event)
{
	char *s1 = "<";
	char *s2 = "Skip";
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
			guider_load_screen(SCR_SETUP);
		}
		
		
    }
}