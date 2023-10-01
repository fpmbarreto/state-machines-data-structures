#include <stdint.h>

extern uint32_t _stackptr;
extern uint32_t _etext;
extern uint32_t _sdata;
extern uint32_t _edata;
extern uint32_t __bss_start__;
extern uint32_t __bss_end__;

void Reset_Handler(void);
void main(void);

/*Alias all exceptions and interrupts to Default_Handler*/
void NMI_Handler(void)                      __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));
void MemManage_Handler(void)                __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler(void)               __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler(void)                      __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void Systick_Handler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void WWDG_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void PVD_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void TAMP_STAMP_IRQHandler(void)            __attribute__ ((weak, alias("Default_Handler")));
void RTC_WKUP_IRQHandler(void)              __attribute__ ((weak, alias("Default_Handler")));
void FLASH_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void RCC_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void EXTI0_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void EXTI1_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void EXTI2_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void EXTI3_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void EXTI4_IRQHandler(void)                 __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream0_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream2_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream4_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream6_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void ADC_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void EXTI9_5_IRQHandler(void)               __attribute__ ((weak, alias("Default_Handler")));
void TIM1_BRK_TIM9_IRQHandler(void)         __attribute__ ((weak, alias("Default_Handler")));
void TIM1_UP_TIM10_IRQHandler(void)         __attribute__ ((weak, alias("Default_Handler")));
void TIM1_TRG_COM_TIM11_IRQHandler(void)    __attribute__ ((weak, alias("Default_Handler")));
void TIM1_CC_IRQHandler(void)               __attribute__ ((weak, alias("Default_Handler")));
void TIM2_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void TIM3_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void TIM4_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void I2C1_EV_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void I2C1_ER_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void I2C2_EV_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void I2C2_ER_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void SPI1_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void SPI2_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void USART1_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void USART2_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void EXTI15_10_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));
void RTC_Alarm_IRQHandler(void)             __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_WKUP_IRQHandler(void)           __attribute__ ((weak, alias("Default_Handler")));
void DMA1_Stream7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void SDIO_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void TIM5_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void SPI3_IRQHandler(void)                  __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream0_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream1_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream2_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream3_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream4_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void OTG_FS_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream5_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream6_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void DMA2_Stream7_IRQHandler(void)          __attribute__ ((weak, alias("Default_Handler")));
void USART6_IRQHandler(void)                __attribute__ ((weak, alias("Default_Handler")));
void I2C3_EV_IRQHandler(void)               __attribute__ ((weak, alias("Default_Handler")));
void I2C3_ER_IRQHandler(void)               __attribute__ ((weak, alias("Default_Handler")));
void FPU_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void SPI4_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));
void SPI5_IRQHandler(void)                   __attribute__ ((weak, alias("Default_Handler")));



uint32_t vector_table[] __attribute__ ((section(".isr_vector_table")))= {
    (uint32_t)&_stackptr,
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    (uint32_t)&MemManage_Handler,
    (uint32_t)&BusFault_Handler,
    (uint32_t)&UsageFault_Handler,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,
    (uint32_t)&DebugMon_Handler,
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&Systick_Handler,
    (uint32_t)&WWDG_IRQHandler,
    (uint32_t)&PVD_IRQHandler,
    (uint32_t)&TAMP_STAMP_IRQHandler,
    (uint32_t)&RTC_WKUP_IRQHandler,
    (uint32_t)&FLASH_IRQHandler,
    (uint32_t)&RCC_IRQHandler,
    (uint32_t)&EXTI0_IRQHandler,
    (uint32_t)&EXTI1_IRQHandler,
    (uint32_t)&EXTI2_IRQHandler,
    (uint32_t)&EXTI3_IRQHandler,
    (uint32_t)&EXTI4_IRQHandler,
    (uint32_t)&DMA1_Stream0_IRQHandler,
    (uint32_t)&DMA1_Stream1_IRQHandler,
    (uint32_t)&DMA1_Stream2_IRQHandler,
    (uint32_t)&DMA1_Stream3_IRQHandler,
    (uint32_t)&DMA1_Stream4_IRQHandler,
    (uint32_t)&DMA1_Stream5_IRQHandler,
    (uint32_t)&DMA1_Stream6_IRQHandler,
    (uint32_t)&ADC_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t)&EXTI9_5_IRQHandler,
    (uint32_t)&TIM1_BRK_TIM9_IRQHandler,
    (uint32_t)&TIM1_UP_TIM10_IRQHandler,
    (uint32_t)&TIM1_TRG_COM_TIM11_IRQHandler,
    (uint32_t)&TIM1_CC_IRQHandler,
    (uint32_t)&TIM2_IRQHandler,
    (uint32_t)&TIM3_IRQHandler,
    (uint32_t)&TIM4_IRQHandler,
    (uint32_t)&I2C1_EV_IRQHandler,
    (uint32_t)&I2C1_ER_IRQHandler,
    (uint32_t)&I2C2_EV_IRQHandler,
    (uint32_t)&I2C2_ER_IRQHandler,
    (uint32_t)&SPI1_IRQHandler,
    (uint32_t)&SPI2_IRQHandler,
    (uint32_t)&USART1_IRQHandler,
    (uint32_t)&USART2_IRQHandler,
    0,
    (uint32_t)&EXTI15_10_IRQHandler,
    (uint32_t)&RTC_Alarm_IRQHandler,
    (uint32_t)&OTG_FS_WKUP_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t)&DMA1_Stream7_IRQHandler,
    0,
    (uint32_t)&SDIO_IRQHandler,
    (uint32_t)&TIM5_IRQHandler,
    (uint32_t)&SPI3_IRQHandler,
    0,
    0,
    0,
    0,
    (uint32_t)&DMA2_Stream0_IRQHandler,
    (uint32_t)&DMA2_Stream1_IRQHandler,
    (uint32_t)&DMA2_Stream2_IRQHandler,
    (uint32_t)&DMA2_Stream3_IRQHandler,
    (uint32_t)&DMA2_Stream4_IRQHandler,
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&OTG_FS_IRQHandler,
    (uint32_t)&DMA2_Stream5_IRQHandler,
    (uint32_t)&DMA2_Stream6_IRQHandler,
    (uint32_t)&DMA2_Stream7_IRQHandler,
    (uint32_t)&USART6_IRQHandler,
    (uint32_t)&I2C3_EV_IRQHandler,   
    (uint32_t)&I2C3_ER_IRQHandler,
    0,
    0,
    0,
    0,
    0,  
    0,
    0,
    (uint32_t)&FPU_IRQHandler,
    0,
    0,
    (uint32_t)&SPI4_IRQHandler,
    (uint32_t)&SPI5_IRQHandler
};

/*Define Default Handler that will work as a weak attribute of all unused interrupts*/
void Default_Handler(void)
{
    while(1);
}

/*Entry Point*/
void Reset_Handler(void)
{
    /*Get data and bss memory sections size*/
    uint32_t data_mem_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t bss_mem_size = (uint32_t)&__bss_end__ - (uint32_t)&__bss_start__;

    /*Copy data from FLASH to SRAM*/
    uint32_t *ptr_src_mem = (uint32_t)&_etext;
    uint32_t *ptr_dest_mem = (uint32_t)&_sdata;

    for(uint32_t i = 0; i < data_mem_size; i++)
    {
        *ptr_dest_mem++ = *ptr_src_mem++;
    }

    /*Initialize BSS section with 0's*/
    ptr_dest_mem = (uint32_t)&__bss_start__;
    for(uint32_t i = 0; i < __bss_end__; i++)
    {
        *ptr_dest_mem++ = (uint32_t)0x00;
    }

    main();
}