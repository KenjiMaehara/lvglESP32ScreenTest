
#include "events_init.h"
#include <stdio.h>
#include <lvgl.h>
#include "custom.h"
#include <Arduino.h>
//#include "devIO.h"




void events_init(lv_ui *ui)
{
	events_init_home(ui);
}

static void home_back_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press KeySet\n");            
	switch (event)
	{
        case LV_EVENT_PRESSED:
        {
            guider_load_screen(SCR_HOME);
            printf("press SCR_HOME\n");            
        }
		break;
	default:
		break;
	}
}


static void home_imgbtnKeySetevent_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press KeySet\n");            
	switch (event)
	{
        case LV_EVENT_PRESSED:
        {
            guider_load_screen(SCR_LOADER);
            printf("press KeySet\n");            
        }
		break;
	default:
		break;
	}
}

static void home_imgbtnSetupevent_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press Setup\n");            
	switch (event)
	{
		//case LV_EVENT_PRESSED:
		case LV_EVENT_LONG_PRESSED_REPEAT:
		{
    	        guider_load_screen(SCR_LOADER);   
				printf("load LODER handler\n");     
    	        add_loader(load_keypad);
				printf("press Setup\n"); 
		}
			break;
		default:
			break;
	}
}


static void home_imgbtnSetupevent2_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press Setup\n");            
	switch (event)
	{
		//case LV_EVENT_PRESSED:
		case LV_EVENT_LONG_PRESSED_REPEAT:
		{
    	        guider_load_screen(SCR_LOADER);   
				printf("load LODER handler\n");     
    	        add_loader(load_keypad);
				printf("press Setup\n"); 
		}
			break;
		default:
			break;
	}
}



static void setup_area_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press Setup\n");            
	switch (event)
	{
		//case LV_EVENT_PRESSED:
		case LV_EVENT_LONG_PRESSED_REPEAT:
		{
    	        //guider_load_screen(SCR_LOADER);   
				//printf("load LODER handler\n");     
    	        guider_load_screen(SCR_AREA);
				printf("press Setup\n"); 
		}
			break;
		default:
			break;
	}
}



static void home_imgbtnCardSetupevent_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press CardSetup\n");            
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
            guider_load_screen(SCR_LOADER);
            printf("press CardSetup\n");            
		
	}
		break;
	default:
		break;
	}
}

static void home_imgbtnWifiSetupevent_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press WifiSetup\n");            
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
            guider_load_screen(SCR_WIFI_HOME);
            printf("press WifiSetup\n");            
	}
		break;
	default:
		break;
	}
}


static void home_TimeShow_handler(lv_obj_t * obj, lv_event_t event)
{
            printf("pre  press WifiSetup\n");            
	switch (event)
	{
		case LV_EVENT_LONG_PRESSED_REPEAT:
		{
    		guider_load_screen(SCR_LOADER);   
			printf("load LODER handler\n");     
    	    guider_load_screen(SCR_TIME_SHOW);
    	    printf("press WifiSetup\n");            
		}
			break;
		default:
			break;
	}
}

void events_init_home(lv_ui *ui)
{
	printf("11111111111111111\n");
	lv_obj_set_event_cb(ui->home_imgbtnKeySet, home_imgbtnKeySetevent_handler);
	printf("22222222222222\n");
	lv_obj_set_event_cb(ui->home_imgbtnSetup, home_imgbtnSetupevent_handler);
	printf("333333333333333\n");
	lv_obj_set_event_cb(ui->home_imgbtnCardSetup, home_imgbtnCardSetupevent_handler);
	printf("44444444444444444\n");
	lv_obj_set_event_cb(ui->home_imgbtnWifiSetup, home_imgbtnWifiSetupevent_handler);
	printf("5555555555555\n");
}

static void keypad_btnm0event_handler(lv_obj_t * obj, lv_event_t event)
{
	switch (event)
	{
	case LV_EVENT_PRESSED:
	{
		const char * txt = lv_btnmatrix_get_active_btn_text(obj);
		//io_buzzer_onoff(true);
		delay(100);
		//io_buzzer_onoff(false);
		printf("%s was pressed\n",txt);
	}
		break;
	default:
		break;
	}
}

void events_init_keypad(lv_ui *ui)
{
	lv_obj_set_event_cb(ui->keypad_btnm0, keypad_btnm0event_handler);
}


void setup_select_function_init(lv_ui *ui)
{
	printf("11111111111111111\n");
	lv_obj_set_event_cb(ui->setup_select_function6_btn, home_TimeShow_handler);
	printf("2222222222222222\n");
	lv_obj_set_event_cb(ui->setup_select_function7_btn, home_imgbtnSetupevent2_handler);
	printf("3333333333333333\n");
	lv_obj_set_event_cb(ui->setup_select_function8_btn, setup_area_handler);

	//lv_obj_set_event_cb(ui->home_back, home_back_handler);

}

#if 0
void setup_backHome_init(lv_ui *ui)
{
	printf("11111111111111111\n");
	lv_obj_set_event_cb(ui->home_labelKeySet, home_back_handler);

}
#endif