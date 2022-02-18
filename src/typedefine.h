#ifndef __TYPEDEF_H_
#define __TYPEDEF_H_

typedef signed char _SBYTE;
typedef unsigned char _UBYTE;
typedef signed short _SWORD;
typedef unsigned short _UWORD;
typedef signed int _SINT;
typedef unsigned int _UINT;
typedef signed long _SDWORD;
typedef unsigned long _UDWORD;


typedef unsigned char   BYTE; /* Unsigned 8 bit quantity */
typedef unsigned short  WORD; /* Unsigned 16 bit quantity */ 
typedef unsigned long 	LONG; /* Unsigned 32 bit quantity */
typedef unsigned long 	DWORD; /* Unsigned 32 bit quantity */

typedef unsigned char   u8; /* Unsigned 8 bit quantity */
typedef unsigned short  u16; /* Unsigned 16 bit quantity */ 
typedef unsigned long 	u32; /* Unsigned 32 bit quantity */


typedef volatile unsigned char   vu8; /* Unsigned 8 bit quantity */
typedef volatile unsigned short  vu16; /* Unsigned 16 bit quantity */ 
typedef volatile unsigned long 	vu32; /* Unsigned 32 bit quantity */

//typedef unsigned long time_t;
typedef volatile unsigned char VBYTE;

//typedef unsigned char bool;
typedef enum
{
    MNT_INT_CARD=0,
    MNT_EXT_CARD,
    MNT_KEY,
    MNT_SW,
    MNT_MANUAL,
    MNT_LAN_CARD,
    MNT_REMOTE,
    MNT_AUTO,
    MNT_LOCAL,
    MNT_WIRELESS
};

enum CONN_TYPE {
	CONN_PSTN=0,
	CONN_PVC,
	CONN_TCP,
	CONN_MSG
};


enum JUR_STATE {
	JUR_KIND_SR = 0,  // set/reset
	JUR_KIND_CTL,     // 컨트롤
	JUR_KIND_REMOTE,  // 리모트
	JUR_KIND_DEVICE,  // 기기이상
	JUR_KIND_SENSOR,  // 센서
	JUR_KIND_COMM,    // 통신 에러
	JUR_KIND_SYSTEM,
	JUR_KIND_OTHER
};

enum JUR_CTL_METHOD{
	JUR_CTL_MANUAL = 0,  
	JUR_CTL_AUTO
};

enum JUR_CTL_ACT{
	JUR_CTL_OFF = 0,  
	JUR_CTL_ON,
	JUR_CTL_OERR
};

#if 0
typedef enum {
    true = 1, 
    TRUE = 1, 
    false = 0, 
    FALSE = 0 
} bool;
#endif

#if 0
struct tm
{
  int tm_sec;                   // Seconds after the minute [0, 59]
  int tm_min;                   // Minutes after the hour [0, 59]
  int tm_hour;                  // Hours since midnight [0, 23]
  int tm_mday;                  // Day of the month [1, 31]
  int tm_mon;                   // Months since January [0, 11]
  int tm_year;                  // Years since 1900
  int tm_wday;                  // Days since Sunday [0, 6]
  int tm_yday;                  // Days since January 1 [0, 365]
  int tm_isdst;                 // Daylight Saving Time flag
};
#endif


#define		OFF		0
#define		ON		1
#define		UNUSED	0xf

#define		LOW		0
#define		HIGH	1

#define		FALSE	0
#define		TRUE	1

#define		false	0
#define		true	1

#define		INSERT	0
#define		EDIT	1
#define		DELETE  2

#define		plus	1
#define		minus	0

#define     NO      0
#define     NC      1

#define     RESET   0
#define     SET     1

#define		C_ON	0
#define		C_OFF	1

#define 	HALF_HOUR_SEC	1800
#define		HOUR_SEC		3600

#define LOOPBACK			2
#define WSENSOR_SCH_ERR_ON	3
#define WSENSOR_SCH_ERR_OFF	4
#define WSENSOR_BAT_ON		5
#define WSENSOR_BAT_OFF		6
#define WSENSOR_TAMPA_ON	7
#define WSENSOR_TAMPA_OFF	8


enum COMM_SIGNAL {
	SET_RESET_SIG=0,
	SCHDULE_SIG,
	BAT_LOW_SIG,
	SENSOR_SIG,
	SET_MISS_SIG,
	STATUS_SIG,
	LOOP_BACK_SIG,
	W_SCH_ERROR_SIG,
	W_BAT_LOW_SIG,
	IF_SIG,
	MSG_SIG,
	LAN_CARD_SIG,
	LAN_SENSOR_SIG,	
	TCP_ALIVE_SIG,
	MULTI_ERROR_SIG,
	LAN_CARD_ERROR_SIG,	
	M06_ERROR_SIG,
	ERROR_MSG_SIG,	
	PVC_RES_SIG,
	PVC_STATUS_SIG,
	PVC_STATUS_NEW_CARD_SIG,
	PVC_DATA_SIG,
	LAN_TAMPA_SIG,
	LAN_LNS_SIG,
	LAN_SAC_SIG,
	W_TAMPA_SIG,
	EXT_FAIL_SIG,

	NONE_SIG	
};

enum _SAC_SIG_TYPE_ {
	SAC_LOCK_ERR,
	SAC_UNLOCK_ERR,
	SAC_LOCK_DOOR_OPEN,
	SAC_LOCK_DOOR_OPEN2,
	SAC_TAMPA_IN,
	SAC_TAMPA_OUT,
	SAC_IN_CARD,
	SAC_OUT_CARD,
	SAC_INOUT_BTN,
	SAC_INOUT_BTN2,
	SAC_OPEN_MANUAL,
	SAC_REMOTE_IN,
	SAC_REMOTE_OUT,
	SAC_SENSOR_OUT,
	SAC_INOUT_MANAGER_ERR,	
	SAC_LOCAL_IN,
	SAC_LOCAL_OUT,
	
};

enum _DEVICE_TYPE_{
	LAN_S8=0,
	LAN_SA,
	LAN_SAC,
	LAN_MULTI_SAC,
	LAN_DEVICE1,
	LAN_M06,
	LAN_NONE	
};

enum JUR_COMM_RES {
	JUR_COMM_LINE_ERROR=0,
	JUR_COMM_LINE_BUSY,
	JUR_COMM_FORCE_CALL,
	JUR_COMM_SCH_CALL,
	JUR_COMM_UNKNOWN_END,
	JUR_COMM_END,
	JUR_COMM_ERROR,
	JUR_COMM_UNKNOWN,
	JUR_COMM_TA_ERROR,
//	JUR_COMM_LINE_OK,
	JUR_COMM_LINE_ERROR_OK,
	JUR_COMM_LINE_BUSY_OK
};	

enum JUR_SYSTEM_KIND {
	JUR_SYSTEM_BOOT=0,
	JUR_SYSTEM_FIRMWARE_UPDATE,
	JUR_SYSTEM_IF_MEMORY_CLEAR,
	JUR_SYSTEM_COMM_BUF_CLEAR,
	JUR_SYSTEM_JUR_CLEAR,
	JUR_SYSTEM_SET_DEFAULT
};	


enum JUR_SYSTEM_METHOD {
	JUR_SYSTEM_MANUAL=0,	
	JUR_SYSTEM_TCP,
};

enum JUR_START_MODE {
	JUR_RESET =0,
	JUR_SET,
	JUR_COM_RESET,
	JUR_COM_SET,
	JUR_MAINTENCE,
	JUR_SET_MISS,
};

enum JUR_SR_METHOD {
	JUR_SR_MET_KEY = 0,  // Key
	JUR_SR_MET_INT_CARD, // 내부 카드리더
	JUR_SR_MET_EXT_CARD, // 외부 카드리더
	JUR_SR_MET_SW,       // 스위치
	JUR_SR_MET_WIRE,     // Wireless
	JUR_SR_MET_SR,       // S/R Key
	JUR_SR_MET_LAN,      // LAN
	JUR_SR_MET_REMOTE,
	JUR_SR_MET_AUTO,
	JUR_SR_MET_LOCAL
};

enum JUR_DEVICE_DATA {
	JUR_DEVICE_ERR=0,
	JUR_DEVICE_OK,
	JUR_DEVICE_BAT,
	JUR_DEVICE_TAMPA_ON,
	JUR_DEVICE_TAMPA_OFF
};
	
enum JUR_DEVICE_SET {
	JUR_MO6=0,
	JUR_LAN,
	JUR_WIRELESS,
	JUR_MULTI,
	JUR_IF
};

enum JUR_REMOTE_COMM {
	JUR_REMOTE_PSTN=0,
	JUR_REMOTE_PVC,
	JUR_REMOTE_TCP,
};


enum JUR_REMOTE_DATA {
	JUR_REMOTE_UPLOAD=0,
	JUR_REMOTE_DOWNLOAD,
	JUR_REMOTE_UNKNOWN1,
	JUR_REMOTE_COMM_ERR,
	JUR_REMOTE_COMM_OK,
	JUR_REMOTE_SET,
	JUR_REMOTE_RESET,
	JUR_REMOTE_CTL,
	JUR_REMOTE_SCH
};


enum ENV_LAN_TYPE
{
	ENV_LAN_NONE=0,
	ENV_LAN_MO6_MULTI,
	ENV_LAN_MO6_SA,
	ENV_LAN_MO6_SAC,
	ENV_LAN_MO6_S1,
	ENV_LAN_MO6_S8,
	ENV_LAN_MO6_AE,
};

#endif