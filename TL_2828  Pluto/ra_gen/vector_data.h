/* generated vector header file - do not edit */
        #ifndef VECTOR_DATA_H
        #define VECTOR_DATA_H
                /* Number of interrupts allocated */
        #ifndef VECTOR_DATA_IRQ_COUNT
        #define VECTOR_DATA_IRQ_COUNT    (11)
        #endif
        /* ISR prototypes */
        void r_icu_isr(void);
        void ctsu_write_isr(void);
        void ctsu_read_isr(void);
        void ctsu_end_isr(void);
        void sci_uart_rxi_isr(void);
        void sci_uart_txi_isr(void);
        void sci_uart_tei_isr(void);
        void sci_uart_eri_isr(void);
        void lvd_lvd_isr(void);
        void gpt_counter_overflow_isr(void);

        /* Vector table allocations */
        #define VECTOR_NUMBER_ICU_IRQ0 ((IRQn_Type) 0) /* ICU IRQ0 (External pin interrupt 0) */
        #define VECTOR_NUMBER_CTSU_WRITE ((IRQn_Type) 1) /* CTSU WRITE (Write request interrupt) */
        #define VECTOR_NUMBER_CTSU_READ ((IRQn_Type) 2) /* CTSU READ (Measurement data transfer request interrupt) */
        #define VECTOR_NUMBER_CTSU_END ((IRQn_Type) 3) /* CTSU END (Measurement end interrupt) */
        #define VECTOR_NUMBER_SCI2_RXI ((IRQn_Type) 4) /* SCI2 RXI (Receive data full) */
        #define VECTOR_NUMBER_SCI2_TXI ((IRQn_Type) 5) /* SCI2 TXI (Transmit data empty) */
        #define VECTOR_NUMBER_SCI2_TEI ((IRQn_Type) 6) /* SCI2 TEI (Transmit end) */
        #define VECTOR_NUMBER_SCI2_ERI ((IRQn_Type) 7) /* SCI2 ERI (Receive error) */
        #define VECTOR_NUMBER_LVD_LVD1 ((IRQn_Type) 8) /* LVD LVD1 (Voltage monitor 1 interrupt) */
        #define VECTOR_NUMBER_GPT5_COUNTER_OVERFLOW ((IRQn_Type) 10) /* GPT5 COUNTER OVERFLOW (Overflow) */
        #define VECTOR_NUMBER_GPT6_COUNTER_OVERFLOW ((IRQn_Type) 14) /* GPT6 COUNTER OVERFLOW (Overflow) */
        typedef enum IRQn {
            Reset_IRQn = -15,
            NonMaskableInt_IRQn = -14,
            HardFault_IRQn = -13,
            MemoryManagement_IRQn = -12,
            BusFault_IRQn = -11,
            UsageFault_IRQn = -10,
            SecureFault_IRQn = -9,
            SVCall_IRQn = -5,
            DebugMonitor_IRQn = -4,
            PendSV_IRQn = -2,
            SysTick_IRQn = -1,
            ICU_IRQ0_IRQn = 0, /* ICU IRQ0 (External pin interrupt 0) */
            CTSU_WRITE_IRQn = 1, /* CTSU WRITE (Write request interrupt) */
            CTSU_READ_IRQn = 2, /* CTSU READ (Measurement data transfer request interrupt) */
            CTSU_END_IRQn = 3, /* CTSU END (Measurement end interrupt) */
            SCI2_RXI_IRQn = 4, /* SCI2 RXI (Receive data full) */
            SCI2_TXI_IRQn = 5, /* SCI2 TXI (Transmit data empty) */
            SCI2_TEI_IRQn = 6, /* SCI2 TEI (Transmit end) */
            SCI2_ERI_IRQn = 7, /* SCI2 ERI (Receive error) */
            LVD_LVD1_IRQn = 8, /* LVD LVD1 (Voltage monitor 1 interrupt) */
            GPT5_COUNTER_OVERFLOW_IRQn = 10, /* GPT5 COUNTER OVERFLOW (Overflow) */
            GPT6_COUNTER_OVERFLOW_IRQn = 14, /* GPT6 COUNTER OVERFLOW (Overflow) */
        } IRQn_Type;
        #endif /* VECTOR_DATA_H */