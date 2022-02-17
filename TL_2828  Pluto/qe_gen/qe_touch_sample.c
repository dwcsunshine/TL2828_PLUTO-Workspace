/***********************************************************************
*
* FILE : qe_sample_main.c
* DATE : 2020-09-10
* DESCRIPTION : Main Program
*
* NOTE:THIS IS A TYPICAL EXAMPLE.
*
***********************************************************************/
#include "qe_touch_config.h"
#define TOUCH_SCAN_INTERVAL_EXAMPLE (1)    /* milliseconds */


void qe_touch_Init(void);
uint8_t qe_getvalue(void);
void qe_Touch_close(void);
uint8_t qe_getvalueInit(void);

uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif



void qe_Touch_close(void)
{
	 fsp_err_t err;
	RM_TOUCH_Close(g_qe_touch_instance_config01.p_ctrl);
//	err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
//    if (FSP_SUCCESS != err)
//    {
//        while (true) {}
//    }
}

	volatile uint32_t tmp1,tmp2;
   static uint16_t      g_touch_button_countvaluelast[3];
   static uint16_t     g_touch_button_referencelast[3];

   static uint16_t Timeout[6]={0};
   static uint16_t Timeout1[6]={0};
   static uint16_t Timeout2[3]={0};
void qe_touch_Init(void)
{
    volatile fsp_err_t err;
	 
	err=RM_TOUCH_Close(g_qe_touch_instance_config01.p_ctrl);
    /* Open Touch middleware */
    err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }
	memset(&g_touch_button_countvaluelast[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&g_touch_button_referencelast[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout1[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
	memset(&Timeout2[0],0,TOUCH_CFG_NUM_BUTTONS*sizeof(uint16_t));
}
static uint16_t cnt = 600;
uint8_t qe_getvalueInit(void)
{
	fsp_err_t err;
	err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }
    while (0 == g_qe_touch_flag) {}
    g_qe_touch_flag = 0;

	button_status = 0;
    err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
			return (uint8_t)button_status;
}

uint8_t qe_getvalue(void)
{

	fsp_err_t err;
	uint8_t i =0;

	err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
    if (FSP_SUCCESS != err)
    {
        while (true) {}
    }
     while (0 == g_qe_touch_flag) {}
    g_qe_touch_flag = 0;

	button_status = 0;
    err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
    if (FSP_SUCCESS == err)
    {
		
			tmp1 = g_touch_button_reference[0];//+g_touch_button_reference[1]+g_touch_button_reference[2];
			tmp2 = g_touch_button_countvalue[0];//+g_touch_button_countvalue[1]+g_touch_button_countvalue[2];
			if(tmp1>50000 || tmp2>50000) //??¨°a??????????????????¡Á??¦Ì??????????????????¦Ì????????????????????? ????????????????3???¨º???????????????????
			{
				qe_touch_Init();
			
			}	
			else if(tmp1<12000 || tmp2<12000) //??¨°a??????????????????¡Á??¦Ì??????????????????¦Ì????????????????????? ????????????????3???¨º???????????????????
			{
			qe_touch_Init();
			
			}	
			else
			{
				for(i=0;i<0;i++)
				{
					if(g_touch_button_reference[i]>g_touch_button_countvalue[i])
						Timeout1[i]+=1;
					else
						Timeout1[i]=0;
					if(Timeout1[i]>=2000) // ¦Ì¡À?¨´¡Á??¦Ì¨°??¡À¡ä¨®¨®¨²?¨¬2a?¦Ì ¡À¡ê3?5S
					{
						qe_touch_Init() ;//
						 break;
					}
				}
			
				for(i=0;i<1;i++)
				{
					if(i<3)
					{
						if(g_touch_button_countvaluelast[i] != g_touch_button_countvalue[i])
						{
							g_touch_button_countvaluelast[i]= g_touch_button_countvalue[i];
							Timeout[i] = 0;
						}
						else
						{
							Timeout[i]+=1;
						
						}
					}
					if(Timeout[i]>=3000)  //¨¢?D?15S¡ã¡ä?¨¹¦Ì?¨¨?¨°a¨°????¨¹?¦Ì2???¡À? ?¨°??DD3?¨º??¡¥
					{
						 qe_touch_Init();//
						 break;
					}
				}

				for(i=0;i<1;i++)
				{
					if(g_touch_button_referencelast[i] != g_touch_button_reference[i])
					{
						g_touch_button_referencelast[i] = g_touch_button_reference[i];
						Timeout2[i] = 0;
					}
					else
					{
						Timeout2[i]+=1;
					
					}
					if(Timeout2[i]>=10000)  //¨¢?D?50S?¨´¡Á??¦Ì?T¡À??¡¥
					{
						 qe_touch_Init();//
						 break;
					}
				}

//				if(button_status==0) //¦Ì¡À¡ã¡ä?¨¹??¨®D¡ã¡ä??
//				{
//					for(i=0;i<6;i++)
//					{
//						if(i<3)
//						{
//							if(g_touch_button_countvaluelast[i]>14800)
//							{
//								g_touch_button_countvaluelast[i]= g_touch_button_countvalue[i];
//								Timeout1[i] = 0;
//							}
//							else
//							{
//								Timeout1[i]+=1;
//							
//							}
//						}
//						else
//						{
//							if(g_touch_button_referencelast[i-3] >14800)
//							{
//								Timeout1[i] = 0;
//							}
//							else
//							{
//								Timeout1[i]+=1;
//							}
//						}
//						if(Timeout1[i]>=1000)  //¨¨?¨°a¡ã¡ä?¨¹D?¨®¨²14800?¨´¡Á??¦Ì ?¨°??D?3?¨º??¡¥ ¨¢?D?5S
//						{
//							 qe_touch_Init();//
//							 break;
//						}
//					}
//					
//				}
//				else
//				{
//					memset(&Timeout1[0],0,6);
//				}
			}
		
        /* TODO: Add your own code here. */
    }


	
    /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
//    R_BSP_SoftwareDelay(TOUCH_SCAN_INTERVAL_EXAMPLE, BSP_DELAY_UNITS_MILLISECONDS);
	return (uint8_t)button_status;
	
}
