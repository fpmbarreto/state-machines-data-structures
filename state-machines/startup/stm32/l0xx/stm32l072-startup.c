#include <stdint.h>

/*
Build
main.o : arm-none-eabi-gcc -c -mcpu=cortex-M0 -mthumb -std=gnu11 main.c -o main.o
stm32L0x_startup.o : arm-none-eabi-gcc -c -mcpu=cortex-M0 -mthumb -std=gnu11 stm32L0x_startup.c -o stm32L0x_startup.o
stm32_blink.elf : arm-none-eabi-gcc -nostdlib -T stm32_ls.ld *.o -o stm32_blink.elf -Wl,-Map=stm32_blink.map

Load to the STM32 board:
openocd -f board/stm32l0discovery.cfg
*/

extern uint32_t _estack;           //End of stack memory
extern uint32_t _etext;            //End of .text memory section
extern uint32_t _sdata;            //Start of .data memory section
extern uint32_t _edata;            //End of .data memory section
extern uint32_t _sbss;             //Start of .bss memory section
extern uint32_t _ebss;             //End of .bss memory section
extern uint32_t _ldata;            //Address where .data is loaded

void Reset_Handler(void);
int main(void);

void NMI_Handler                    (void)__attribute__((weak,alias("Default_Handler")));
void HardFault_Handler              (void)__attribute__((weak,alias("Default_Handler")));
void SVC_Handler                    (void)__attribute__((weak,alias("Default_Handler")));
void PendSV_Handler                 (void)__attribute__((weak,alias("Default_Handler")));
void SysTick_Handler                (void)__attribute__((weak,alias("Default_Handler")));
void WWDG_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void PVD_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void RTC_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void FLASH_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void RCC_CRS_IRQHandler             (void)__attribute__((weak,alias("Default_Handler")));
void EXTI1_0_IRQHandler             (void)__attribute__((weak,alias("Default_Handler")));
void EXTI2_3_IRQHandler             (void)__attribute__((weak,alias("Default_Handler")));
void EXTI15_4_IRQHandler            (void)__attribute__((weak,alias("Default_Handler")));
void TSC_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_CH1_IRQHandler            (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_CH3_2_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void DMA1_CH7_4_IRQHandler          (void)__attribute__((weak,alias("Default_Handler")));
void ADC_COMP_IRQHandler            (void)__attribute__((weak,alias("Default_Handler")));
void LPTIM1_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void USART4_5_IRQHandler            (void)__attribute__((weak,alias("Default_Handler")));
void TIM2_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void TIM3_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void TIM6_DAC_IRQHandler            (void)__attribute__((weak,alias("Default_Handler")));
void TIM7_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void TIM21_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C3_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void TIM22_IRQHandler               (void)__attribute__((weak,alias("Default_Handler")));
void I2C1_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void I2C2_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void SPI1_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void SPI2_IRQHandler                (void)__attribute__((weak,alias("Default_Handler")));
void USART1_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void USART2_IRQHandler              (void)__attribute__((weak,alias("Default_Handler")));
void LPUART1_AES_RNG_IRQHandler     (void)__attribute__((weak,alias("Default_Handler")));
void USB_IRQHandler                 (void)__attribute__((weak,alias("Default_Handler")));

//Can be consulted in MCU's RM
uint32_t vector_tbl[] __attribute__((section(".isr_vector_tbl"))) = {
    (uint32_t)&_estack,                     //First element from interrupt stack routine. 
    (uint32_t)&Reset_Handler,
    (uint32_t)&NMI_Handler,
    (uint32_t)&HardFault_Handler,
    0,                                     //Reserved from 0x10 to 0x2B --> 7 uint32_t 0's
    0,
    0,
    0,
    0,
    0,
    0,
    (uint32_t)&SVC_Handler,             
    0,                                     //Reserved from 0x30 to 0x37 --> 2 uint32_t 0's
    0,
    (uint32_t)&PendSV_Handler,
    (uint32_t)&SysTick_Handler,            //Above - Interrupt Requests (IRQ) from peripherals or software
    (uint32_t)&WWDG_IRQHandler,            //Window Watchdogg Interrupt
    (uint32_t)&PVD_IRQHandler,             //PVD through EXTI (External Input) Line detection Interrupt
    (uint32_t)&RTC_IRQHandler,             //RTC global interrupt through EXTI17/19/20 line and LSE CSS interrupt through EXTI 19 line
    (uint32_t)&FLASH_IRQHandler,           //Flash memory and data EEPROM global interrupt
    (uint32_t)&RCC_CRS_IRQHandler,         //RCC and CRS global interrupt
    (uint32_t)&EXTI1_0_IRQHandler,         //EXTI Line0 and 1 interrupts
    (uint32_t)&EXTI2_3_IRQHandler,         //EXTI Line2 and 3 interrupts
    (uint32_t)&EXTI15_4_IRQHandler,        //EXTI Line4 and 15 interrupts
    (uint32_t)&TSC_IRQHandler,             //Touch Sense Controller interrupt   
    (uint32_t)&DMA1_CH1_IRQHandler,        //DMA1 Channel1 global interrupt 
    (uint32_t)&DMA1_CH3_2_IRQHandler,      //DMA1 CHannel2 and 3 interrupts
    (uint32_t)&DMA1_CH7_4_IRQHandler,      //DMA1 Channel4 and 7 interrupts
    (uint32_t)&ADC_COMP_IRQHandler,        //ADC and Comparator interrupts through EXTI21/22
    (uint32_t)&LPTIM1_IRQHandler,          //LPTIMER1 interrupt through EXTI29
    (uint32_t)&USART4_5_IRQHandler,        //USART4/USART5 global interrupt
    (uint32_t)&TIM2_IRQHandler,            //TIMER2 global interrupt
    (uint32_t)&TIM3_IRQHandler,            //TIMER3 global interrupt 
    (uint32_t)&TIM6_DAC_IRQHandler,        //TIMER6 global interrupt and DAC interrupt
    (uint32_t)&TIM7_IRQHandler,            //TIMER7 global interrupt
    0,
    (uint32_t)&TIM21_IRQHandler,           //TIMER21 global interrupt
    (uint32_t)&I2C3_IRQHandler,            //I2C3 global interrupt 
    (uint32_t)&TIM22_IRQHandler,           //TIMER22 global interrupt
    (uint32_t)&I2C1_IRQHandler,            //I2C1 global interrupt through EXTI23
    (uint32_t)&I2C2_IRQHandler,            //I2C2 global interrupt       
    (uint32_t)&SPI1_IRQHandler,            //SPI1 global interrupt
    (uint32_t)&SPI2_IRQHandler,            //SPI2 global interrupt
    (uint32_t)&USART1_IRQHandler,          //USART1 global interrupt through EXTI25
    (uint32_t)&USART2_IRQHandler,          //USART2 global interrupt through EXTI26
    (uint32_t)&LPUART1_AES_RNG_IRQHandler, //LPUART1 global interrupt through EXTI28/AES global interrupt/RNG global interrupt
    0,
    (uint32_t)&USB_IRQHandler,             //USB event interrupt through EXTI28
};

void Default_Handler(void){
    while(1);
    //Do nothing
}

/*Entry Point*/
void Reset_Handler(void){
    uint32_t data_mem_size = (uint32_t)&_edata - (uint32_t)&_sdata;
    uint32_t bss_mem_size = (uint32_t)&_ebss - (uint32_t)&_sbss;

    uint32_t *p_src_mem = (uint32_t *)&_ldata;
    uint32_t *p_dest_mem = (uint32_t *)&_sdata;

    for (uint32_t i= 0; i < data_mem_size; i++){
        //Copy data section from FLASH to SRAM;
        *p_dest_mem++ = *p_src_mem++;
    }

    p_dest_mem = (uint32_t*)&_sbss;

    for (uint32_t i = 0; i < bss_mem_size; i++){
        //Set .bss section to 0
        *p_dest_mem++ = 0;
    }

    main();
}