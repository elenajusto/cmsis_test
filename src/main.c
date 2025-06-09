#include "nucleof4.h"
#include "baremetal/io.h"
#include "baremetal/clock.h"

/* Delay */
void ms_delay(int ms) {
    while (ms-- > 0) {
        volatile int x = 500;
        while (x-- > 0)
            __asm("nop");
    }
}

/* Program Entry Point */
int main(void) {

    // Enable system clock
    rcc_system_setup();

    // Enable peripheral clocks
    rcc_peripheral_setup();

    // Configure PA5 as output
    gpio_init_output(LED_PORT, LED_PIN);

    /* Main Loop */
    while (1) {
        ms_delay(1500);
        LED_PORT->ODR ^= (1 << LED_PIN); // Toggle LED
    }
    return 0;
}
