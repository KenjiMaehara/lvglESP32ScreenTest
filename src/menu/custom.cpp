// SPDX-License-Identifier: MIT
// Copyright 2020 NXP

/**
 * @file custom.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <lvgl.h>
#include "custom.h"

int cur_scr;
/*Colors*/
#define LV_MENU_WHITE           lv_color_hex(0xffffff)
#define LV_MENU_LIGHT           lv_color_hex(0xf3f8fe)
#define LV_MENU_GRAY            lv_color_hex(0x8a8a8a)
#define LV_MENU_LIGHT_GRAY      lv_color_hex(0xc4c4c4)
#define LV_MENU_BLUE            lv_color_hex(0x2f3243) //006fb6
#define LV_MENU_GREEN           lv_color_hex(0x4cb242)
#define LV_MENU_RED             lv_color_hex(0xd51732)

#define LV_MENU_ANIM_Y (LV_VER_RES / 20)
#define LV_MENU_ANIM_DELAY (40)
#define LV_MENU_ANIM_TIME  (150)
#define LV_MENU_ANIM_TIME_BG  (300)
#define LOAD_ANIM_TIME 1000
lv_anim_t ani_en_btn_click;

static uint16_t printusbcnt = 1;
static uint16_t copynextcnt = 1;
static uint16_t hue_act;
static int16_t lightness_act;
static lv_style_t img_style;

static uint16_t save_src = 0;
char label[20] = {0};
void cnt_event_cb(struct _lv_obj_t * obj, lv_event_t event)
{
    
    if (event == LV_EVENT_PRESSED) 
	{
 #if 0
		if(guider_ui.copynext == lv_scr_act()) 
		{
            if (obj == guider_ui.copynext_up) {
                if (copynextcnt < 200)
                    copynextcnt++;
                sprintf(label, "%d", copynextcnt);
                lv_label_set_text(guider_ui.copynext_labelcnt, label);
            } else {
                if (copynextcnt > 1)
                    copynextcnt--;
                sprintf(label, "%d", copynextcnt);
                lv_label_set_text(guider_ui.copynext_labelcnt, label);

            }
        } else if (guider_ui.prtusb == lv_scr_act()) {
            if (obj == guider_ui.prtusb_up) {
                if (printusbcnt < 200)
                    printusbcnt++;
                sprintf(label, "%d", printusbcnt);
                lv_label_set_text(guider_ui.prtusb_labelcnt, label);
            } else {
                if (printusbcnt > 1)
                    printusbcnt--;
                sprintf(label, "%d", printusbcnt);
                lv_label_set_text(guider_ui.prtusb_labelcnt, label);
            }
        }
#endif		
    }
}

void lv_menu_anim_in_all(lv_obj_t * obj, uint32_t delay)
{
    lv_coord_t y;
    lv_obj_t * child = lv_obj_get_child_back(obj, NULL);
    while(child) {
        y = lv_obj_get_y(child);
        if (child != lv_scr_act()  && child != guider_ui.saved_img1) {
            lv_anim_t a;
            lv_anim_init(&a);
            lv_anim_set_var(&a, child);
            lv_anim_set_time(&a, LV_MENU_ANIM_TIME);
            lv_anim_set_delay(&a, delay);
            lv_anim_set_exec_cb(&a, (lv_anim_exec_xcb_t) lv_obj_set_y);

            if(y > 150)
                lv_anim_set_values(&a, 270, y);
            else
                lv_anim_set_values(&a, 0, y);
            
            lv_anim_start(&a);

            lv_obj_fade_in(child, LV_MENU_ANIM_TIME - 50, delay);
        }
        child = lv_obj_get_child_back(obj, child);
    }
}

void loader_anim_cb(void * arc, lv_anim_value_t v)
{
    if(v > 100) v = 100;
    lv_arc_set_angles((lv_obj_t *)arc, 270, v * 360 / 100 + 270);

    static char buf[32];
    lv_snprintf(buf, sizeof(buf), "%d %%", v);
	lv_label_set_text(guider_ui.loader_loadlabel, buf);
}

void add_loader(void (*end_cb)(lv_anim_t *))
{
    lv_anim_t a;
	lv_arc_set_angles(guider_ui.loader_loadarc, 270, 270);
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, loader_anim_cb);
    lv_anim_set_ready_cb(&a, end_cb);
    lv_anim_set_values(&a, 0, 110);
    lv_anim_set_time(&a, LOAD_ANIM_TIME);
    lv_anim_set_var(&a, guider_ui.loader_loadarc);
    lv_anim_start(&a);
}

lv_obj_t **get_scr_by_id(int scr_id)
{
    if(scr_id == SCR_HOME)
        return &guider_ui.home;
    else if(scr_id == SCR_SETUP)
        return &guider_ui.setup;
    else if(scr_id == SCR_LOADER)
        return &guider_ui.loader;
    else if(scr_id == SCR_SAVED)
        return &guider_ui.saved;
    else if(scr_id == SCR_KEYPAD)
        return &guider_ui.keypad;  
    else if(scr_id == SCR_ALARM)
        return &guider_ui.alarm;  
    else if(scr_id == SCR_WIFI_HOME)
        return &guider_ui.wifi_home;  
    return NULL;
}
void guider_load_screen(int scr_id)
{
    lv_obj_t **scr = NULL;
    lv_obj_t **old_scr = NULL;

    switch(scr_id)
    {
        case SCR_HOME:
            if(!guider_ui.home) {
                scr = &guider_ui.home;
                setup_scr_home(&guider_ui);
                // event_cb();
           //     home_event_init();
            //    lv_anim_set_var(&ani_en_btn_click, guider_ui.home_imgbtncopy);
            //    lv_anim_start(&ani_en_btn_click);
                printf("load home\n");
            }
            break;
        case SCR_SETUP:
            if(!guider_ui.setup) {
                scr = &guider_ui.setup;
                setup_scr_setup(&guider_ui);
                // event_cb();
                setup_event_init();
                printf("load setup\n");
            }
            break;
        case SCR_LOADER:
            if(!guider_ui.loader) {
                scr = &guider_ui.loader;
                setup_scr_loader(&guider_ui);
                // event_cb();
                loader_event_init();
                printf("load LOADER\n");
            }
            break;
        case SCR_SAVED:
            if(!guider_ui.saved) {
                scr = &guider_ui.saved;
                setup_scr_saved(&guider_ui);
                // event_cb();
                saved_event_init();
            }
            break;
		case SCR_KEYPAD:
            if(!guider_ui.keypad) {
                scr = &guider_ui.keypad;
                setup_scr_keypad(&guider_ui);
                // event_cb();
                keypad_event_init();
                printf("load KEYPAD\n");
            }

			break;
		case SCR_ALARM:
            if(!guider_ui.alarm) {
                scr = &guider_ui.alarm;
                setup_scr_alarm(&guider_ui);
				
                // event_cb();
                //alarm_event_init();
            }

			break;	
		case SCR_WIFI_HOME:
            if(!guider_ui.wifi_home) {
                scr = &guider_ui.wifi_home;
                //setup_scr_wifi_home(&guider_ui);
                setup_select_function(&guider_ui);
                //task_unlock(event_lock);
				
                // event_cb();
                //alarm_event_init();
                printf("load WIFI SETUP\n");
            }

			break;		      
		case SCR_TIME_SHOW:
            if(!guider_ui.home) {
                scr = &guider_ui.home;
                //setup_scr_wifi_home(&guider_ui);
                setup_time_function(&guider_ui);
                //task_unlock(event_lock);
				
                // event_cb();
                //alarm_event_init();
                printf("load TIME SHOW\n");
            }
			break;	      		
        case SCR_AREA:
            if(!guider_ui.keypad) {
                scr = &guider_ui.keypad;
                //setup_scr_wifi_home(&guider_ui);
                setup_scr_area(&guider_ui);
                //setup_scr_keypad(&guider_ui);
                //task_unlock(event_lock);
				
                // event_cb();
                //alarm_event_init();
                printf("load AREA\n");
            }
			break;	 
    }
    lv_scr_load(*scr);
    old_scr = get_scr_by_id(cur_scr);
    lv_obj_clean(*old_scr);
    lv_obj_del(*old_scr);
    
    *old_scr = NULL;
    // if(*old_scr != guider_ui.home) {
    //     lv_obj_clean(*old_scr);
    //     *old_scr = NULL;
    // } else {
    //     printf("load home\n");
    // }
    cur_scr = scr_id;

}
void load_home(lv_anim_t *a) {
    guider_load_screen(SCR_HOME);
}

void load_setup(lv_anim_t *a) {
    guider_load_screen(SCR_KEYPAD);
    lv_menu_anim_in_all(guider_ui.keypad, 200);
}

void load_save(lv_anim_t *a) 
{
    guider_load_screen(SCR_SAVED);
    if (save_src == 1) {
        lv_obj_set_x(guider_ui.saved_label2, 187);
        lv_label_set_text(guider_ui.saved_label2, "File saved");
    } else if (save_src == 2) {
        lv_obj_set_x(guider_ui.saved_label2, 157);
        lv_label_set_text(guider_ui.saved_label2, "Printing finished");
    } else {
        lv_obj_set_x(guider_ui.saved_label2, 187);
        lv_label_set_text(guider_ui.saved_label2, "File saved");
    }
    
    lv_menu_anim_in_all(guider_ui.saved, 200);
}

void load_keypad(lv_anim_t *a) {
    guider_load_screen(SCR_KEYPAD);
    lv_menu_anim_in_all(guider_ui.keypad, 200);
}

void load_alarm(lv_anim_t *a) {
    guider_load_screen(SCR_ALARM);
    lv_menu_anim_in_all(guider_ui.alarm, 200);
}

void load_wifi_home(lv_anim_t *a) {
    guider_load_screen(SCR_WIFI_HOME);
    lv_menu_anim_in_all(guider_ui.wifi_home, 200);
}

void load_area(lv_anim_t *a) {
    guider_load_screen(SCR_AREA);
    lv_menu_anim_in_all(guider_ui.keypad, 200);
}

void en_click_anim_cb(void * btn, lv_anim_value_t v)
{
    if(v >= LV_MENU_ANIM_TIME) {
        switch (cur_scr) {
            case SCR_HOME:
                lv_obj_set_click(guider_ui.home_imgbtnKeySet, true);
                lv_obj_set_click(guider_ui.home_imgbtnWifiSetup, true);
                lv_obj_set_click(guider_ui.home_imgbtnCardSetup, true);
                lv_obj_set_click(guider_ui.home_imgbtnSetup, true);
                break;
            case SCR_SETUP:
                break;
            case SCR_LOADER:
                break;
            case SCR_SAVED:
                break;
			case SCR_KEYPAD:
				break;
			case SCR_ALARM:
				lv_obj_set_click(guider_ui.alarm, true);
				break;
			case SCR_WIFI_HOME:
                break;
        
        }
    }
}

void load_home_cb(struct _lv_obj_t * obj, lv_event_t event)
{
 if (event == LV_EVENT_PRESSED) {
    guider_load_screen(SCR_HOME);
    lv_menu_anim_in_all(guider_ui.home, 200);
    }
}



void load_save_cb(struct _lv_obj_t * obj, lv_event_t event){
    
    if (event == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_LOADER);
        save_src = 1;
        add_loader(load_save);
    }
}

// hong
void load_keypad_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_KEYPAD);
        lv_menu_anim_in_all(guider_ui.keypad, 200);
    }
}

void load_alarm_cb(struct _lv_obj_t * obj, lv_event_t event){
 if (event == LV_EVENT_PRESSED) {
        guider_load_screen(SCR_ALARM);
        lv_menu_anim_in_all(guider_ui.alarm, 200);
    }
}



static lv_style_t style_backbtn;
static lv_style_t style_upbtn;
static lv_style_t style_downbtn;
static lv_style_t arc_style;

void home_event_init(void)
{
    lv_obj_set_click(guider_ui.home_imgbtnCardSetup, false);
    lv_obj_set_click(guider_ui.home_imgbtnWifiSetup, false);
    lv_obj_set_click(guider_ui.home_imgbtnSetup, false);
    lv_obj_set_click(guider_ui.home_imgbtnKeySet, false);
    lv_menu_anim_in_all(guider_ui.home, 200);
}
void setup_event_init(void)
{
   // lv_obj_set_event_cb(guider_ui.setup_btnsetback, load_disbtn_home_cb);
}
void loader_event_init(void)
{
    lv_obj_add_style(guider_ui.loader_loadarc, LV_STATE_DEFAULT, &arc_style);

}
void saved_event_init(void)
{
    //lv_obj_set_event_cb(guider_ui.saved_btnsavecontinue, load_disbtn_home_cb);
}

void keypad_event_init(void)
{
    //lv_obj_set_event_cb(guider_ui.saved_btnsavecontinue, load_disbtn_home_cb);
}

void wifi_home_event_init(void)
{
    //lv_obj_set_event_cb(guider_ui.saved_btnsavecontinue, load_disbtn_home_cb);
}


void event_cb(void)
{
    lv_style_init(&style_backbtn);
    lv_style_set_value_str(&style_backbtn, LV_STATE_DEFAULT, LV_SYMBOL_LEFT);
    lv_style_set_value_color(&style_backbtn, LV_STATE_DEFAULT, LV_MENU_WHITE);
    lv_style_set_value_color(&style_backbtn, LV_STATE_PRESSED, LV_MENU_LIGHT_GRAY);

    lv_style_init(&style_upbtn);
    lv_style_set_value_str(&style_upbtn, LV_STATE_DEFAULT, LV_SYMBOL_UP);
    lv_style_set_value_color(&style_upbtn, LV_STATE_DEFAULT, LV_MENU_WHITE);
    lv_style_set_value_color(&style_upbtn, LV_STATE_PRESSED, LV_MENU_LIGHT_GRAY);

    lv_style_init(&style_downbtn);
    lv_style_set_value_str(&style_downbtn, LV_STATE_DEFAULT, LV_SYMBOL_DOWN);
    lv_style_set_value_color(&style_downbtn, LV_STATE_DEFAULT, LV_MENU_WHITE);
    lv_style_set_value_color(&style_downbtn, LV_STATE_PRESSED, LV_MENU_LIGHT_GRAY);

    lv_style_init(&arc_style);
    lv_style_init(&img_style);
    lv_style_set_border_width(&arc_style, LV_STATE_DEFAULT, 0);
    
    lightness_act = 0;
    hue_act = 180;
    
    lv_anim_init(&ani_en_btn_click);
    lv_anim_set_exec_cb(&ani_en_btn_click, en_click_anim_cb);
    lv_anim_set_values(&ani_en_btn_click, 0, LV_MENU_ANIM_TIME);
    lv_anim_set_time(&ani_en_btn_click, LV_MENU_ANIM_TIME);
}

/**
 * Create a demo application
 */

void custom_init(lv_ui *ui)
{
    setup_scr_home(ui);
	event_cb();
	home_event_init();
	cur_scr = SCR_HOME;
	ui->setup = NULL;
	ui->loader = NULL;
	ui->saved = NULL;
	ui->keypad = NULL;
	ui->alarm =NULL;
    ui->wifi_home = NULL;

	lv_scr_load(ui->home);
}


void update_time(char * date)
{
    if(cur_scr == SCR_HOME)
    {//lv_obj_get_screen(guider_ui.home_labeldate) == lv_scr_act()) 
        lv_label_set_text(guider_ui.home_labeldate,date);
    }
}


void update_onlyData(char * date)
{
    if(cur_scr == SCR_TIME_SHOW)
    {
        lv_label_set_text(guider_ui.home_labeldateOnly,date);
    }
}

void update_onlyTime(char * date)
{
    if(cur_scr == SCR_TIME_SHOW)
    {
        lv_label_set_text(guider_ui.home_labelTimeOnly,date);
    }
}