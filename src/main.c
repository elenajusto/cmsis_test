#include "nucleof4.h"
#include "baremetal/io.h"

/* Delay */
void ms_delay(int ms) {
    while (ms-- > 0) {
        volatile int x = 500;
        while (x-- > 0)
            __asm("nop");
    }
}

/* Setup Clocks
*
*  Tutorial Reference: https://controllerstech.com/stm32-clock-setup-using-registers/
*  Datasheet Reference: RM0368 Rev 6
*/
void rcc_setup(void) {

    // 1. ENABLE HSE and wait for the HSE to become Ready
    RCC->CR |= RCC_CR_HSEON;
    while (!(RCC->CR & (1U << 17))) {
    }

	// 2. Set the POWER ENABLE CLOCK and VOLTAGE REGULATOR
    RCC->CR |= RCC_APB1ENR_PWREN;
    PWR->CR |= 1<<14; 

	// 3. Configure the FLASH PREFETCH and the LATENCY Related Settings
    // TODO: I don't really understand why we do this part
    FLASH->ACR = FLASH_ACR_PRFTEN | FLASH_ACR_ICEN | FLASH_ACR_DCEN| (5<<0);

	// 4. Configure the PRESCALARS HCLK, PCLK1, PCLK2
    // AHB PR
    RCC->CFGR &= ~(1<<4);
        
    // APB1 PR
    RCC->CFGR |= (5<<10);
        
    // APB2 PR
    RCC->CFGR |= (4<<13);

	// 5. Configure the MAIN PLL
    RCC->PLLCFGR = RCC_PLLCFGR_PLLM_4 | RCC_PLLCFGR_PLLN_8 | RCC_PLLCFGR_PLLP_0| RCC_PLLCFGR_PLLSRC_HSE;

	// 6. Enable the PLL and wait for it to become ready
    RCC->CR |= (1<<24);
    while ( !( RCC->CR & (1<<25) ) ){
    }

	// 7. Select the Clock Source and wait for it to be set
    RCC->CFGR |= (2<<0);
    while ( !( RCC->CFGR & (2<<2) ) ){
    }

    // Enable clock to GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Enable clock to GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

/* Program Entry Point */
int main(void) {

    // Enable clock to GPIOA
    rcc_setup();

    // Configure PA5 as output
    gpio_init_output(LED_PORT, LED_PIN);

    /* Main Loop */
    while (1) {
        ms_delay(1500);
        LED_PORT->ODR ^= (1 << LED_PIN); // Toggle LED
    }

    return 0;
}
