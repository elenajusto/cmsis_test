#include "clock.h"

/* 
*  Setup System Clock
*
*  Tutorial Reference: https://controllerstech.com/stm32-clock-setup-using-registers/
*  Datasheet Reference: RM0368 Rev 6
*
*/
void rcc_system_setup(void) {
    // ENABLE HSE and wait for the HSE to become Ready
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & (1U << 17))) {
    }

	// Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
    RCC->CR |= RCC_APB1ENR_PWREN;
    PWR->CR |= 1<<14; 

	// Configure the FLASH PREFETCH and the LATENCY Related Settings
    // TODO: I don't really understand why we do this part
    FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN| (5<<0);

	// Configure the PRESCALARS HCLK, PCLK1, PCLK2
    RCC->CFGR &= ~(1<<4); // AHB PR
    RCC->CFGR |= (5<<10); // APB1 PR
    RCC->CFGR |= (4<<13); // APB2 PR

	// Configure the MAIN PLL
    RCC->PLLCFGR = RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLN_8 | RCC_PLLCFGR_PLLP_0| RCC_PLLCFGR_PLLSRC_HSE;

	// Enable the PLL and wait for it to become ready
    RCC->CR |= (1<<24);
    while ( !( RCC->CR & (1<<25) ) ){
    }

	// Select the Clock Source and wait for it to be set
    RCC->CFGR |= (2<<0);
    while ( !( RCC->CFGR & (2<<2) ) ){
    }
}


/* 
*  Setup GPIO Peripheral Clocks 
*/
void rcc_peripheral_setup(void){
    // Enable clock to GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Enable clock to GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}