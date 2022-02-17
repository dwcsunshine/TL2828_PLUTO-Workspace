/***************************************************************************
 * Copyright (c) 2018 Koninklijke Philips Electronics N.V.,                *
 * All Rights Reserved.                                                    *
 ***************************************************************************
 * pmLibrary.c
 *
 * Library source file for calculating CUBE sensor pm2.5 value.
 *
 * Created: 2021/05/18
 * Author: Baofeng
 * Version: 0.0.7
 
 *release note:
	V0.0.1: init
	V0.0.2: 1.输出PM2.5上限设置500
			2.修复预热后30秒内数据上升问题
	V0.0.3	18/12/03
			1.修改算法
			2.检测输入补全小数，提高精度补全小数，提高精度
	
	 V0.0.4 2020/04/027 Add India Market
		India Market need to be modify as below demo code:
			1.pmInit(INDIA_MARKET);
			
			
	V0.0.5 2020/05/06
		1.change IC to 431
		
	v0.0.6 2021/03/15
	  		1.Adjust arithmetic for pollution and allergen market	

	v0.0.7 2021/05/18
			1.Add calcIdxa,calcIdxb to set the algorithm coefficient,
			 calcIdxa and calcIdxb input from photosensitive send jig,
			 and calcIdxa,calcIdxb need to save in MCU flash or eeprom
			 memory.
 */

#ifndef _PMLIB_H
#define _PMLIB_H


/******************************************************************************
 * Enum type:   operating_mode_t
 * Remarks:     all operating modes of the air purifier.
 ******************************************************************************/
typedef enum
{
    MODE_MANUAL,
    MODE_GENERAL,
    MODE_ALLERGEN,
    MODE_BACTERIA,
    MODE_NIGHT_SENSE    
}operating_mode_t;

/******************************************************************************
 * Enum type:   ddp_mode_t
 * Remarks:     Air quality parameter to display on the device.
 ******************************************************************************/
typedef enum
{
    DDP_IAI_LEVEL,
    DDP_PM2_5_LEVEL,
    DDP_TVOC_LEVEL
}ddp_mode_t;

/******************************************************************************
 * Enum type:   market_t
 * Remarks:     Market selection for switching modes.
 ******************************************************************************/
typedef enum
{
    POLLUTION_MARKET,
    ALLERGEN_MARKET,
	INDIA_MARKET
}market_t;

/******************************************************************************
 * Function:    pmInit
 * Input:       Selected market:
 *              POLLUTION_MARKET
 *              ALLERGEN _MARKET
 *				INDIA_MARKET
 *				
 *				calcIdxa,calcIdxb:
 *				a,b algorithm coefficient from flash LED jig setting.
 * Return:      None
 * Remarks:     This function initializes the particle sensor library
 ******************************************************************************/
void pmInit(market_t value, signed int calcIdxa, signed int calcIdxb);

/******************************************************************************
 * Function:    pmScan
 * Input:       P1 -> value of IO pin P1 of the sensor.
 * Return:      None
 * Remarks:     This function should be called every 500 microseconds(500us).
 ******************************************************************************/
void pmScan(unsigned char Para1);

/******************************************************************************
 * Function:    pmCalculate
 * Input:       None
 * Return:      None
 * Remarks:     This function should be called every second.
 ******************************************************************************/
void pmCalculate(void);

/******************************************************************************
 * Function:    pmGetPM25Value
 * Input:       None
 * Return:      16 bit PM2.5 value
 * Remarks:     Call this function to return PM2.5 value. If the sensor
 *              is still warming up, this function returns 0x0000.
 *              Use this value to display the value in DDP_PM2_5_LEVEL mode.
 *              Also use this function for the "pm25" communication parameter.
 ******************************************************************************/
unsigned int pmGetPM25Value(void);

/******************************************************************************
 * Function: pmGetIAIValue
 * Input:       operating_mode_t mode -> reflects the current operating mode
 *              ddp_mode_t ddp -> reflects the current device display parameter
 * Return:      16 bit Air Quality value
 * Remarks:     This function returns the AirQuality depending on the current 
 *              operating mode and the dispay status.
 *              Use this function for speed control, AQI led display and
 *              the display value in DDP_IAI_LEVEL mode.
 *              Also use this function for the "iaql" communication parameter.
 ******************************************************************************/
unsigned int pmGetIAIValue(operating_mode_t mode, ddp_mode_t ddp);




#endif // _PMLIB_H
