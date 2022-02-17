/* generated HAL header file - do not edit */
#ifndef HAL_DATA_H_
#define HAL_DATA_H_
#include <stdint.h>
#include "bsp_api.h"
#include "common_data.h"
#include "r_gpt.h"
#include "r_timer_api.h"
#include "r_lvd.h"
#include "r_lvd_api.h"
#include "r_icu.h"
#include "r_external_irq_api.h"
#include "r_sci_uart.h"
            #include "r_uart_api.h"
#include "r_flash_lp.h"
#include "r_flash_api.h"
#include "r_wdt.h"
#include "r_wdt_api.h"
#include "r_adc.h"
#include "r_adc_api.h"
FSP_HEADER
/** Timer on GPT Instance. */
extern const timer_instance_t Timer_125us;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t Timer_125us_ctrl;
extern const timer_cfg_t Timer_125us_cfg;

#ifndef g_Timer_125us
void g_Timer_125us(timer_callback_args_t * p_args);
#endif
/** LVD Instance */
extern const lvd_instance_t g_lvd;

/** Access the LVD instance using these structures when calling API functions directly (::p_api is not used). */
extern lvd_instance_ctrl_t g_lvd_ctrl;
extern const lvd_cfg_t g_lvd_cfg;

#ifndef LVD_Detection
void LVD_Detection(lvd_callback_args_t * p_args);
#endif
/** External IRQ on ICU Instance. */
extern const external_irq_instance_t g_external_irq0;

/** Access the ICU instance using these structures when calling API functions directly (::p_api is not used). */
extern icu_instance_ctrl_t g_external_irq0_ctrl;
extern const external_irq_cfg_t g_external_irq0_cfg;

#ifndef interrupt_irq0_PM25
void interrupt_irq0_PM25(external_irq_callback_args_t * p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer3;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer3_ctrl;
extern const timer_cfg_t g_timer3_cfg;

#ifndef NULL
void NULL(timer_callback_args_t * p_args);
#endif
/** Timer on GPT Instance. */
extern const timer_instance_t g_timer2;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_timer2_ctrl;
extern const timer_cfg_t g_timer2_cfg;

#ifndef Timer_1ms
void Timer_1ms(timer_callback_args_t * p_args);
#endif
/** UART on SCI Instance. */
            extern const uart_instance_t      g_uart2;

            /** Access the UART instance using these structures when calling API functions directly (::p_api is not used). */
            extern sci_uart_instance_ctrl_t     g_uart2_ctrl;
            extern const uart_cfg_t g_uart2_cfg;
            extern const sci_uart_extended_cfg_t g_uart2_cfg_extend;

            #ifndef user_uart_callback
            void user_uart_callback(uart_callback_args_t * p_args);
            #endif
/* Flash on Flash LP Instance. */
extern const flash_instance_t g_flash;

/** Access the Flash LP instance using these structures when calling API functions directly (::p_api is not used). */
extern flash_lp_instance_ctrl_t g_flash_ctrl;
extern const flash_cfg_t g_flash_cfg;

#ifndef NULL
void NULL(flash_callback_args_t * p_args);
#endif
/** WDT on WDT Instance. */
extern const wdt_instance_t g_wdt;

/** Access the WDT instance using these structures when calling API functions directly (::p_api is not used). */
extern wdt_instance_ctrl_t g_wdt_ctrl;
extern const wdt_cfg_t g_wdt_cfg;

#ifndef NULL
void NULL(wdt_callback_args_t * p_args);
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc;

/** Access the ADC instance using these structures when calling API functions directly (::p_api is not used). */
extern adc_instance_ctrl_t g_adc_ctrl;
extern const adc_cfg_t g_adc_cfg;
extern const adc_channel_cfg_t g_adc_channel_cfg;

#ifndef NULL
void NULL(adc_callback_args_t * p_args);
#endif

#define ADC_DMAC_CHANNELS_PER_BLOCK_NULL  2
/** Timer on GPT Instance. */
extern const timer_instance_t g_PWM_motor;

/** Access the GPT instance using these structures when calling API functions directly (::p_api is not used). */
extern gpt_instance_ctrl_t g_PWM_motor_ctrl;
extern const timer_cfg_t g_PWM_motor_cfg;

#ifndef NULL
void NULL(timer_callback_args_t * p_args);
#endif
void hal_entry(void);
void g_hal_init(void);
FSP_FOOTER
#endif /* HAL_DATA_H_ */
