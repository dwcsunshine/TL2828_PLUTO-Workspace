/***************************************************************
               ** File name: hal_entry.h
               ** Created & Modified by: DWC @HET Tech inc
               ** Date: 2021-6-2
 ***************************************************************/
#ifndef __HAL_ENTRY_H
#define __HAL_ENTRY_H

//#define TEST 0

//#define TouchICVersion 0x01

#define PM25LIB (1)
typedef uint8_t u8;
typedef uint16_t  u16;
typedef uint32_t  u32;
#define bit0 0x0001
#define bit1 0x0002
#define bit2 0x0004
#define bit3 0x0008
#define bit4 0x0010
#define bit5 0x0020
#define bit6 0x0040
#define bit7 0x0080
#define bit8 0x0100
#define bit9 0x0200
#define bit10 0x0400
#define bit11 0x0800
#define bit12 0x1000
#define bit13 0x2000
#define bit14 0x4000
#define bit15 0x8000


#define BigtoLittle32(A)   ((( (u32)(A) & 0xff000000) >> 24) | \
                                         (( (u32)(A) & 0x00ff0000) >> 8)   | \
                                         (( (u32)(A) & 0x0000ff00) << 8)   | \
                                         (( (u32)(A) & 0x000000ff) << 24))

#define BigtoLittle16(A)   ((( (u16)(A) & 0xff00) >> 8) | \
                                         (( (u16)(A) & 0x00ff) << 8) )


#define KEY_MODE 0X01
#define KEY_POWER 0X02
#define KEY_POWER_MODE 0X03





#define KEY_FILTER_COUNT  3 //按键滤波延时值（对应时间长短为20乘调用一次间隔的时间=25ms）
#define KEY_LONG_COUNT    400 //长按判断计数延时值 2s
#define KEY_KEEP_COUNT    100 //长按保持时计时值 500ms
#define KEY_PULSE_FILTER_COUNT 2
#define KEY_Available  bit0
#define KEY_LongPress  bit1
#define KEY_LongOnce   bit2
#define KEY_Release    bit3
#define KEY_ShortPress bit4
//#define  KEY_ShortOnce   Bit4

//#define PreLifemaxhour 720 //720小时
#define wifiTimeout   15*60  //wifi 超时时间  15分钟

#define Pin_CheckKEY R_PORT0->PIDR_b.PIDR12   //按键检测 平时为高电平.
#define Pin_CheckPM25  R_PORT2->PIDR_b.PIDR12
#define Pin_CheckPWRPM25  R_PORT0->PIDR_b.PIDR13
#define Pin_CheckMotor  R_PORT2->PIDR_b.PIDR8




#define PWR_PM25_EN()  R_PORT0->PODR_b.PODR13 = 0
#define PWR_PM25_DIS()  R_PORT0->PODR_b.PODR13 = 1
#define PWR_WIFI_EN()   R_PORT0->PODR_b.PODR15 = 1
#define PWR_WIFI_DIS()   R_PORT0->PODR_b.PODR15 = 0
#define PWR_MOTOR_EN()  R_PORT2->PODR_b.PODR6=0
#define PWR_MOTOR_DIS()  R_PORT2->PODR_b.PODR6=1
#define PWR_BUZ_ON()  1
#define PWR_BUZ_OFF()  0

#define  pCom1 R_PORT9->PODR_b.PODR15
#define  pCom2 R_PORT5->PODR_b.PODR0
#define  pCom3 R_PORT1->PODR_b.PODR0
#define  pCom4 R_PORT4->PODR_b.PODR8
#define  pCom5 R_PORT4->PODR_b.PODR9
#define  pCom6 R_PORT1->PODR_b.PODR2
#define  pCom7 R_PORT1->PODR_b.PODR3

#define Icon_Filter()  		tDisp_Buff[3] |= bit0
#define LED_Filter_En()  	pCom5 = 0
#define LED_Filter_Dis()  	pCom5 = 1

#define LED_Ring_Red_En() 	{pCom2=0; pCom3=0;pCom4=0;}
#define LED_Ring_Blue_En()  pCom1=1
#define LED_Ring_Red_Dis()  {pCom2=1; pCom3=1;pCom4=1;}
#define LED_Ring_Blue_Dis()  pCom1=0

#define LED_Ring_Dis()   	{pCom1=0;pCom2=1; pCom3=1;pCom4=1;}
#define LED_Ring_En()   	{pCom1=1;pCom2=0; pCom3=0;pCom4=0;}

#define LED_Wifi_White_En()  pCom6 = 0
#define LED_Wifi_White_Dis()  pCom6 = 1
#define LED_Wifi_Amber_En()  pCom7 = 0
#define LED_Wifi_Amber_Dis()  pCom7 = 1
#define LED_RB1_En()  pCom4 = 0
#define LED_RB1_Dis()  pCom4 = 1
#define LED_RB2_En()  pCom3 = 0
#define LED_RB2_Dis()  pCom3 = 1
#define LED_RB3_En()  pCom2 = 0
#define LED_RB3_Dis()  pCom2 = 1

#define TESTpin_109		R_PORT1->PODR_b.PODR9
















typedef struct
{
	float Kp;
	float Ki;
	float Kd;
	float SpeedFB1;
	float SpeedFB2;
	float E_delta;
	float E_deltasum;
	float E_delta_BIAS;
	float increasement;  // PID的增量
	float output;
} Pid_str;





typedef struct
{
	u16 CalCnt;
	u16 Cnt;//计数
	u16 Buf[10];
	u8 Index;//buf的索引
	u8 CycleCnt;//转一圈判断
	u8 State;//防重复计数
	u8 Cnt_L;
	u8 Cnt_H;
	signed int delta_speed;
} FG_str;

typedef struct
{
	u16 Beep_Dur;  //一个周期内响的时间
	u16 Chime_Due; //整个周期时间
	u16 Freq;   //需要的频率
} Buzparadef;

typedef struct Beat
{
	Buzparadef sta0;
	Buzparadef sta1;
	Buzparadef sta2;
} Buzbeatdef;
typedef struct   //存储需要的蜂鸣器数据
{
	Buzbeatdef Sound_On;
	Buzbeatdef Sound_Off;
	Buzbeatdef Sound_Once;
	Buzbeatdef Sound_Twice;
	Buzbeatdef Sound_Succ;
	Buzbeatdef Sound_Fail;
} Buz_str;



enum
{
	BuzSta_PowerOn = 0,
	BuzSta_PowerOff,
	BuzSta_Once,
	BuzSta_Twice,
	BuzSta_Succ,
	BuzSta_Fail
} eBuzSta;

enum
{
	eLightoff=0,	//只显示灯光滤网
	eLightDim=50,	//全部暗
	eLightNomal=100  //正常显示
} eLightsta;


enum
{
	eddpIAI=0,
	eddpPM25
} eDDP;



#define Buz_PowerOn()  {eBuzSta=BuzSta_PowerOn;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}
#define Buz_PowerOff()   {eBuzSta=BuzSta_PowerOff;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}
#define Buz_Once()   {eBuzSta=BuzSta_Once;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}
#define Buz_Twice()   {eBuzSta=BuzSta_Twice;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}
#define Buz_Succ()   {eBuzSta=BuzSta_Succ;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}
#define Buz_Fail()   {eBuzSta=BuzSta_Fail;gBuzEnable=1;gBuzbeat=0;gBuzCnt=0;}




typedef struct
{
	u32 P1TotalTime;
//	u16 P1TBuf[30];
	u16 P1Time;//p1在一个周期内低电平的时间
//	u8 Index;
	u8 P1Flag;//开始计时的标志
//	u8 ErrFlag;//传感器故障标志
//	u8 Test30sec;
	u16 PM25; // PM2.5传感器数值
	u16 PM25tmp; // PM2.5传感器数值
	u16 PM25Buf[8];
	u32 PM25Total;
//	u8 KeepCnt;
//	u8 Level;//灰尘等级(最终)
//	u8 P1_Up2sCnt ;
//	u8 P1_Down2MinCnt;
//	u8 ErrCnt;
} Particle_str;











typedef enum
{
	emodeAuto=0,
	emodeSleep,
	emodeTurbo,
	emodeAllergy,
	emodeSpd1,
	emodeSpd2
} emode;

typedef enum
{
	espdOff=0,
	espdSleep,
	espdTurbo,
	espd1,
	espd2,
	espd3
} espd;


typedef struct  // 7.2变更为数组 【0】为计算需要的风速 【1】为实际所需要的风速值
{
	float Spd_Off[2];
	float Spd_Sleep[2];
	float Spd_Turbo[2];
	float Spd1[2];
	float Spd2[2];
	float Spd3[2];
	float Spd_Output[2];
	float Spd_Outputtmp[2]; //输出缓存

} Motor_str;


typedef struct
{
	u16 Plugin_Cnt;  //上电时间计数
	u16 Warmup30s_Cnt;  //开机30S计数
	float FanspeedFB;
	u8 steadyflg; //风速稳定标志
	u8 steadycnt;
	u16 Errcode;  // 故障代码
	u16 lightADvalue_10bit;  //光敏传感器的AD值
	u16 lightADvalue_12bit;  //12bit
	u16 lightADvaluetmp_12bit;  //12bit
	u16 PowerADvalue_12bit;

	u16 checksumOption;// 配置信息校验和
	u16 Wifitimeoutcnt; // wifi配置超时时间 一般按15分钟计算
	u16 WifiCommtimeoutcnt; //wifi模块和窜口通讯超时计数
	u8 LVDcheckflg;  // 低电压检测打开标志位
	u8 Setupflg;  //设备配置标志  经过闪光灯配置才能正常运行
	u8 AQI_LEVEL; //AQI等级  默认全部关闭显示灯
	u8 decoring; // 两色灯的配色
	u8 Wifi_EWS_DONE_flg;  //easy wifi setup标志位 需要存储
	u8 WifiEnable;
	u8 Economic;
	u8 facpm25check;
	u8 Factoryflg;    //长按电源和灯 组合键 15S进入	响2声
	u8 Factorysteps;  //工厂模式测试步骤
	u8 Factorywifisteps; //工厂模式wifi步骤 1 2 3
	u8 FilterTestFlg;   //长按组合按键 开关机和模式键 15S进入 响2声
	u8 Sleep3S_Cnt; //3S计数
	u8 eLight20S_Cnt; // 20s计数
	u8 PM25_Sleepcoefficent;  //PM25系数
	u8 PM25_Turbocoefficent;  // PM25系数
	u8 IAQL_memvalue; //IAI 掉电记忆数据
	u8 	motorpwmoutput;  //根据总电压判断电机是否能够输出频率
	u16 PM25_memvalue;//PM25掉电记忆数据
	signed int PM25_TFa;
	signed int PM25_TFb;  //  pm25库里面使用
	u8 wifisetcnt;  // wifi 配网次数

} Sys_str;


typedef struct
{
	u8 Storeflg;  // 滤网存储标志
	u8 Forcereset_3S_Cnt; // 滤网强制恢复 3秒显示处理
	u16 Flow[6]; // 滤网CCM计算相关 风速流量
	u16 NormalLifeloweresthour ;//普通滤网工作时间 小时 最小值
	u16 NormalLifemaxhour;  //普通滤网最大值 小时
	u16 PreLifemaxhour;  //预置滤网最大值
	u32 Disppercentage;  //滤网显示百分比
	u32 TLSLpercentage;
	u32 TUSLpercentage;
	u32 CCMpercentage;
	u32 Time1S_Cnt ; // 滤网计数  每秒计算
	u32 CCMmgmax_mg;  //CCM的数量总量 单位是毫克
	u32 CCMcurrent_ug; //CCM当前的数量 微克
	u32 CCMremaining_mg;//CCM剩余数量
	u32 CCMaccumulated_ugtmp; //CCM累计数量   缓存使用
	u16 Normalaccumulated_hourtmp; //滤网累加的工作时间
	u16 Preaccumulated_hourtmp; //预置滤网累计工作时间
	u32 CCMaccumulated_ug; //CCM累计数量
	u16 Normalaccumulated_hour; //滤网累加的工作时间
	u16 Normalaccumulated_10min; //滤网累加的工作时间  10min计时
	u16 Preaccumulated_hour; //预置滤网累计工作时间
	u16 Preremaining_hour; // 预置滤网剩余时间
	u16 Normalremaining_hour; // 普通滤网剩余时间
} Filter_str;

#define RTxData_Max  250  //最多接收的数据个数

enum areatype
{
	eAREA_EU=0,
	eAREA_CN,
	eAREA_ASEAN,
	eAREA_TH,
	eAREA_UK_HK,
	eAREA_LAT,
	eAREA_INDIA,
	eAREA_ANZ,
	eAREA_CN_TW,
	eAREA_JAPAN,
	eAREA_BNL,
	eAREA_CEE,
	eAREA_MET,
	eAREA_DACH,
	eAREA_Indonesia,
	eAREA_AU
} eArea;


enum edecoringtype
{
	edeco_Pink =0,
	edeco_Normal
} edecoring;



enum colortype
{
	ecolor_white=0,
	ecolor_lack,
	ecolor_gray,
	ecolor_pink
} ecolor;

typedef enum
{
	ID_Initial=1,  //初始化 1
	ID_Inirespons,	//初始化的回复 2
	ID_Putprops,  //下发数据 3
	ID_Getprops,	//获取数据 4
	ID_Subscribe,  //订阅 5
	ID_Unsubscribe, //解除订阅 6
	ID_Response, //基准回复 7
	ID_ChangeIndicationResponse, //8 变更指示的回复
	ID_ChangeIndication  //9变更指示

} eIDtypedef;

typedef enum
{
	Port_device=1,  //设备
	Port_wifiui,	//wifi连接和设置状态
	Port_air,  //空气净化器的属性
	Port_fac,		//工程模式
	Port_fltsts,	//读取滤网属性
	Port_flttest,  //设置滤网属性（仅仅用于测试）
	Port_network,		//wifi节点的网络信息
	Port_otau,	//重启设备进入引导程序
	Port_otaf,  //SPI falsh  OTA (不使用)
	Port_wififeatures		//wifi节点设备设置（不使用）


} ePortdef;

typedef enum
{
	wifi_C_not_connected=1,
	wifi_C_requested,

	wifi_C_connecting,
	wifi_C_connected,
	wifi_C_error
} eWifi_cdef;

typedef enum
{
	wifi_S_inactive=1,
	wifi_S_requested,
	wifi_S_active
} eWifi_sdef;

#pragma pack (1)  //强制地址按1字节对齐

typedef struct
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16 portpollinginterval;
	} para1;	//	Indicates the interval of the port polling. In seconds.
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 category	;	//	Device category (Purifier, Humidifier or Robot Vacuum Cleaner)
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 name[30]	;	//	The product name, set by the user (e.g. “Kitchen”, etc.)
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 productrange[30]	;	//	Product range, to facilitate for example OTAU
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 ctn[30]	;	//	Device type as defined in the Philips systems
	} para5;
//	struct
//	{
//		u8 Props;
//		u8 Lenths;
//		u8 serial[25]	;	//	unique identifier of the connected product instance
//	}para6;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 language	;	//	Language as used on the display of the device
	} para7;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 wifiprotocolversion	;	//	Version of the Wi-Fi protocol used.
	} para8;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 OTAUprotocolversion	;	//	The actual OTAU protocol version.
	} para9;

	struct
	{
		u8 Props;
		u8 Lenths;
		enum areatype area	;	//	SKU 国家和地区 enum
	} paraA;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 color	;	//	颜色 enum
	} paraB;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 wifimodulefwversion[6]	;	//	Actual version of the Wi-Fi module firmware
	} para10;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 node0bootloaderversion[6]	;	//	Actual version of the bootloader of Node 0
	} para11;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 node0applicationversion[6]	;	//	Actual version of the application of Node 0
	} para12;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 node0touchicversion[6]	;	//	Actual version of the touchic of Node 0
	} para13;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16 node0bootloaderchecksum	;	//	Actual version of the bootloaderchecksum of Node 0
	} para14;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16 node0Applicationchecksum	;	//	Actual version of the node0Applicationchecksum of Node 0
	} para15;
} Port_devicedef;




/*
not connected	inactive	OFF	Initialization.
not connected	requested	AMBER blink @ 1Hz	Device request WIFI module to start EWS. It will take some time for the Wi-Fi module to start the AP mode. The LED gives feedback to the user.
not connected	active	AMBER blink @ 1Hz	Wi-Fi module is in AP mode.
connected	active	AMBER on	Cell phone connected with Wi-Fi module.
connecting	active	WHITE blink @ 1Hz	Wi-Fi module (STA) is trying to connect to the SSID using the password sent by APP (encrypted, only for MXchip solution).
connecting	inactive	WHITE blink @ 1Hz	Wi-Fi module (STA) is trying to connect to the SSID using the password sent by APP (encrypted, only for MXchip solution).
connected	inactive	WHITE on	Wi-Fi module (STA) connected with router.
requested	inactive	OFF	Device requests Wi-Fi module to start connection with the stored SSID network.
connecting	inactive	WHITE blink @ 1Hz	Wi-Fi module (STA) is connecting router.
error	inactive		Error.
*/
typedef struct
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval	;	//	Indicates the interval of the port polling. In seconds. 00: Time interval 0x0001-0xFFFF
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	connection	;	//	0x01: “not connected”0x02: “requested”0x03: “connecting”0x04: “connected”0x05: “error”
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	setup	;	//	0x01: “inactive”0x02: “requested”0x03: “active”
	} para3;
} Port_wifiuidef;

typedef struct
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval 	;	//	Indicates the interval of the port polling
	} para1;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	power	;	//	Indicates the power state
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	childLock	;	//	Indicates whether the device is in Child Lock mode or not.
	} para3;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	AQILight	;	//	Indicates and sets the state of the AQI light.
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	UIlight ;	//	Indicates and sets the state of the UI light.
	} para5;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	userautomodesetting ;	//	Indicates which auto mode had been set by the user first time to choose(Pollution, Allergen, Gas, HCHO)
	} para6;

	struct
	{
		u8 Props;
		u8 Lenths;
		emode	opmode	;	//	Indicates the operation mode of the purifier (the fan speed). The different operation modes are described in the table below.
	} para7;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	fanspeed	;	//	Indicates the operation mode of the purifier (the fan speed). The different operation modes are described in the table below.
	} para8;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	iaql	;	//	Indicates the intelligent Air Quality Level. (renamed as IAI, indoor air index)
	} para9;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	pm25	;	//	Indicates the measured PM2.5 value.
	} para10;

//	struct
//	{
//		u8 Props;
//		u8 Lenths;
//		u8	gas ;	//	Indicates the measured Gas value.

//	}para11;
//	struct
//	{
//		u8 Props;
//		u8 Lenths;
//		u8	formaldehyde	;	//	Indicates the measured Formaldehyde value. (1 – 200 = 0.01 – 2 mg/m3)
//	}para12;
//	struct
//	{
//		u8 Props;
//		u8 Lenths;
//		int8_t	temperature ;	//	Indicates the measured Temperature value.
//	}para13;

//	struct
//	{
//		u8 Props;
//		u8 Lenths;
//		u8	RH	;	//	Indicates the measured RH value.

//	}para14;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	ddp ;	//	Default Display Parameter: Indicates the favorite device display setting (default display)

	} para15;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	rddp	;	//	Real Device Display Parameter: Indicates which value has to be shown on the device display and the app.
	} para16;

	struct
	{
		u8 Props;
		u8 Lenths;
		u8	aqit	;	//	Indicates the threshold level for notification on Air Quality Level. Default value is 4
	} para17;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	errorcode ;		//	Warning or Error Notification
	} para18;
} Port_airdef;


typedef struct
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval 	;	//	Indicates the interval of the port polling
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	pcba	;	//	0x00 (ready) 0x01(start)
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	wifi	;	//	0x00 (ready) 0x01(start)
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8 reset	;	//	0x00 (ready) 0x01(start)
	} para4;
} Port_facdef;


typedef struct  //除了轮询间隔时间可读可写 其他均只为可读 不可修改
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval 	;	//	Indicates the interval of the port polling
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	filtertype1 ;	//	Indicates the used filter in position 1. Values A1 – A9
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	filtertype2 ;	//	Indicates the used filter in position 2. Values none, C1 – C9
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter0lifetime ;	//	Pre-filter lifetime in hours
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter1lifetime ;	//	Filter 1 lifetime in hours
	} para5;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter2lifetime ;	//	Filter 2 lifetime in hours
	} para6;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter0remaininglifetime	;	//	Pre-filter life (including wick) in hours remaining before cleaning.
	} para7;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter1remaininglifetime	;	//	Filter 1 life in hours remaining before locked (replace).
	} para8;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter2remaininglifetime	;	//	Filter 2 life in hours remaining before locked (replace).
	} para9;
} Port_fltstsdef;


typedef struct  // 均为可读可写
{

	struct
	{
		u8 Props;
		u8 Lenths;

		u16	portpollinginterval 	;	//	Indicates the interval of the port polling in seconds
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	filtertype1 ;	//	Indicates the used filter in position 1. Values A1 – A9
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	filtertype2 ;	//	Indicates the used filter in position 2. Values none, C1 – C9
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter0lifetime ;	//	Pre-filter lifetime in hours
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter1lifetime ;	//	Filter 1 lifetime in hours
	} para5;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter2lifetime ;	//	Filter 2 lifetime in hours
	} para6;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter0remaininglifetime	;	//	Pre-filter life (including wick) in hours remaining before cleaning.
	} para7;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter1remaininglifetime	;	//	Filter 1 life in hours remaining before locked (replace).
	} para8;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	filter2remaininglifetime	;	//	Filter 2 life in hours remaining before locked (replace).
	} para9;
	struct
	{
		u8 Props;
		u8 Lenths;
		u32	filter1CCMcurrent	;	//	For CCM test (mg)
	} para10;
	struct
	{
		u8 Props;
		u8 Lenths;
		u32	filter1lifecurrent	;	//	For filter1 life test (hour)
	} para11;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	K1CountValue	;	//	K1按键检测值
	} para12;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	K1ReferenceValue	;	//	K1按键基准值
	} para13;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	K2CountValue	;	//	K2按键检测值
	} para14;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16 K2ReferenceValue	;	//	K2按键基准值
	} para15;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	K3CountValue	;	//	K3按键检测值
	} para16;

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	K3ReferenceValue	;	//	K3按键基准值
	} para17;
} Port_flttestdef;


typedef struct  // 除了MAC地址不可写，其他均为可读可写
{

	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval 	;	//	Indicates the interval of the port polling in seconds
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	macaddress[6]	;	//	The MAC address of the Wi-Fi node
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	ipaddress[4]	;	//	The IP address of the Wi-Fi node
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	subnetmask[4]	;	//	The network subnet mask
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	wifissid[32]	;	//	The SSID of the Wi-Fi network that the device is connected to
	} para5;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	wifipasscode[63]	;	//	The passcode of the Wi-Fi network
	} para6;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	defaultgateway[4]	;	//	The default gateway address of the Wi-Fi network
	} para7;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	dhcpserver[4]	;	//	The address of the DHCP server of the Wi-Fi network
	} para8;

} Port_networkdef;



/*
“state”: “downloading” means that the Wi-Fi node is transferring the data to device.
“state”: “downloaded” means that the transfer is done.
If the Wi-Fi node sets the value of “state” to “reset” it means that the Wi-Fi node is prepared for downloading, the device needs to jump to the bootloader address for downloading.
If the device sets the value of “state” to “reset”, it means that the Wi-Fi node needs to download the latest version of the device firmware to the device node.
*/
typedef struct  // 除了data只写，其他均为可读可写
{
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	portpollinginterval 	;	//	Indicates the interval of the port polling in seconds
	} para1;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	state	;	//	0x00: “idle”0x01: “downloading”0x02: “downloaded”0x03: “reset”
	} para2;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	devicefirmwareversion[10]	;	//	The IP address of the Wi-Fi node
	} para3;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	currentpackagenumber	;	//	The network subnet mask
	} para4;
	struct
	{
		u8 Props;
		u8 Lenths;
		u16	totalpackagenumber	;	//	The SSID of the Wi-Fi network that the device is connected to
	} para5;
	struct
	{
		u8 Props;
		u8 Lenths;
		u8	data[128]	;	//	The passcode of the Wi-Fi network
	} para6;
	struct
	{
		u8 Props;
		u8 Lenths;
		u32	checksum	;	//	The default gateway address of the Wi-Fi network
	} para7;
} Port_otaudef;

typedef struct
{

	u8 reqVersion;
	u8 clientHints;
	u8 Status;
	u8 WiFiProtocolVersion;
	u8 serverHints;
	u8 reqProps;  // 属性缓存
	u8 reqPropslen;
	u8 reqPort;  //端口
	u8 reqopID;  //操作ID
	u16 CRC; //CRC
	u16 rxPayloadLenth; //数据的长度
	u16 txPayloadLenth; //数据的长度
	Port_devicedef 	Port1_device;
	Port_wifiuidef 	Port2_wifiu;
	Port_airdef 	Port3_air;
	Port_facdef 	Port4_fac;
	Port_fltstsdef 	Port5_fltsts;
	Port_flttestdef	Port6_flttest;
	Port_networkdef	Port7_network;
	Port_otaudef 	Port8_otau;
} DI_str;

struct
{
	u8 Props;
	u8 Lenths;
	u8 name[30] ;	//	The product name, set by the user (e.g. “Kitchen”, etc.)
} devicename;

struct
{
	u8 Props;
	u8 Lenths;
	u8 wifiprotocolversion	;	//	Version of the Wi-Fi protocol used.
} devicewifiprotocolversion;


#pragma pack () //恢复缺省对齐模式



extern DI_str  DI;





#endif // End of define __HAL_ENTRY_H
/***************************************************************
                      ** End of hal_entry.h
***************************************************************/
