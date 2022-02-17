#ifndef Photosensitive_H
#define Photosensitive_H
//----------002-----------------
//Added adjust to receive mobile phone flashlight send data. 

//--------------------------------------------
//	1MS call Photosensitive_scan function once
//Input:	(uint16_t)Photosensitive Adc value
//Output:
//		(uint8_t)0  is No received or CRC error
//		(uint8_t)1  is received success and Please read Pho.Rec_data[0~80]
// 
// 0.0.3 19-02-01
// int change to short
//data buffer change to 10
//0.0.4 190404
// Receive buff length change to 20byte
//--------------------------------------------
extern unsigned char Photosensitive_scan(unsigned short Pho_adc_buff);
//example:FE FF 02 01 00 2E 3E the code is enter factory mode

#define Array_lengh 20

#define Pho_timeout_def		90//90ms receive timeout
#define Pho_sensibility_def 90//调节接收灵敏度，接收波形电压AD差,(0-1023)
#define Pho_STANDBY	0
#define Pho_GUIDE	1
#define Pho_GAP		2
#define PHO_DATA 	3
typedef	struct
{
	unsigned short	Adc_value;
	unsigned short	Adc_ref_last;
	unsigned short	Adc_ref;
	unsigned short	Adc_max;
	unsigned short	Adc_min;
	unsigned char	Adc_count;
}TYP_PH_AD;
typedef	struct
{
	unsigned char		Rec_data[Array_lengh];
	unsigned short		Rec_count;
	unsigned char		Timeout;
	unsigned char		Logic_V;
	unsigned char		High_count;
	unsigned char		Low_count;
	unsigned char		Cycle_count;
	unsigned char		Receive_stage;
	
}TYP_PHO;
extern TYP_PHO 		Pho;
extern TYP_PH_AD 	PH_AD;


#endif
