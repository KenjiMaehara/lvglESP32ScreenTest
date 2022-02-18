

#ifndef EVENTS_INIT_H_
#define EVENTS_INIT_H_

#ifdef __cplusplus
extern "C" {
#endif
#include "gui_guider.h"

void events_init(lv_ui *ui);
void events_init_home(lv_ui *ui);
void events_init_keypad(lv_ui *ui);
void setup_select_function_init(lv_ui *ui);
//void setup_time_function(lv_ui *ui);
void setup_backHome_init(lv_ui *ui);

#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* EVENT_CB_H_ */