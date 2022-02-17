/* generated vector source file - do not edit */
        #include "bsp_api.h"
        /* Do not build these data structures if no interrupts are currently allocated because IAR will have build errors. */
        #if VECTOR_DATA_IRQ_COUNT > 0
        BSP_DONT_REMOVE const fsp_vector_t g_vector_table[BSP_ICU_VECTOR_MAX_ENTRIES] BSP_PLACE_IN_SECTION(BSP_SECTION_APPLICATION_VECTORS) =
        {
                        [0] = r_icu_isr, /* ICU IRQ0 (External pin interrupt 0) */
            [1] = ctsu_write_isr, /* CTSU WRITE (Write request interrupt) */
            [2] = ctsu_read_isr, /* CTSU READ (Measurement data transfer request interrupt) */
            [3] = ctsu_end_isr, /* CTSU END (Measurement end interrupt) */
            [4] = sci_uart_rxi_isr, /* SCI2 RXI (Receive data full) */
            [5] = sci_uart_txi_isr, /* SCI2 TXI (Transmit data empty) */
            [6] = sci_uart_tei_isr, /* SCI2 TEI (Transmit end) */
            [7] = sci_uart_eri_isr, /* SCI2 ERI (Receive error) */
            [8] = lvd_lvd_isr, /* LVD LVD1 (Voltage monitor 1 interrupt) */
            [10] = gpt_counter_overflow_isr, /* GPT5 COUNTER OVERFLOW (Overflow) */
            [14] = gpt_counter_overflow_isr, /* GPT6 COUNTER OVERFLOW (Overflow) */
        };
        const bsp_interrupt_event_t g_interrupt_event_link_select[BSP_ICU_VECTOR_MAX_ENTRIES] =
        {
            [0] = BSP_PRV_IELS_ENUM(EVENT_ICU_IRQ0), /* ICU IRQ0 (External pin interrupt 0) */
            [1] = BSP_PRV_IELS_ENUM(EVENT_CTSU_WRITE), /* CTSU WRITE (Write request interrupt) */
            [2] = BSP_PRV_IELS_ENUM(EVENT_CTSU_READ), /* CTSU READ (Measurement data transfer request interrupt) */
            [3] = BSP_PRV_IELS_ENUM(EVENT_CTSU_END), /* CTSU END (Measurement end interrupt) */
            [4] = BSP_PRV_IELS_ENUM(EVENT_SCI2_RXI), /* SCI2 RXI (Receive data full) */
            [5] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TXI), /* SCI2 TXI (Transmit data empty) */
            [6] = BSP_PRV_IELS_ENUM(EVENT_SCI2_TEI), /* SCI2 TEI (Transmit end) */
            [7] = BSP_PRV_IELS_ENUM(EVENT_SCI2_ERI), /* SCI2 ERI (Receive error) */
            [8] = BSP_PRV_IELS_ENUM(EVENT_LVD_LVD1), /* LVD LVD1 (Voltage monitor 1 interrupt) */
            [10] = BSP_PRV_IELS_ENUM(EVENT_GPT5_COUNTER_OVERFLOW), /* GPT5 COUNTER OVERFLOW (Overflow) */
            [14] = BSP_PRV_IELS_ENUM(EVENT_GPT6_COUNTER_OVERFLOW), /* GPT6 COUNTER OVERFLOW (Overflow) */
        };
        #endif