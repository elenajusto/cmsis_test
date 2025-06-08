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

/* Setup Clocks*/
void rcc_setup(void) {
    // Enable clock to GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Enable clock to GPIOC
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

/* Main Loop */
int main(void) {

    // Enable clock to GPIOA
    rcc_setup();

    // Configure PA5 as output
    gpio_init_output(LED_PORT, LED_PIN);

    while (1) {
        ms_delay(1500);
        LED_PORT->ODR ^= (1 << LED_PIN); // Toggle LED
    }

    return 0;
}
