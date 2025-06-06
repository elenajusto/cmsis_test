#include "stm32f4xx.h"

// =======================
// Pin Definitions
// =======================
#define LED_PORT GPIOA
#define LED_PIN  5

void notUsed(){
    int localUnused;
};

// =======================
// Function Prototypes
// =======================
void gpio_init_output(GPIO_TypeDef *port, uint32_t pin);
void ms_delay(int ms);

// =======================
// Delay Function (Quick + Dirty)
// =======================
void ms_delay(int ms) {
    while (ms-- > 0) {
        volatile int x = 500;
        while (x-- > 0)
            __asm("nop");
    }
}

// =======================
// GPIO Output Init
// =======================
void gpio_init_output(GPIO_TypeDef *port, uint32_t pin) {
    // 1. Clear mode bits
    port->MODER &= ~(0x3 << (pin * 2));
    // 2. Set mode to '01' (general purpose output)
    port->MODER |=  (0x1 << (pin * 2));

    // Optional: Output type = push-pull (0)
    port->OTYPER &= ~(1 << pin);

    // Optional: Output speed = high speed (11)
    port->OSPEEDR |= (0x3 << (pin * 2));

    // Optional: No pull-up, pull-down (00)
    port->PUPDR &= ~(0x3 << (pin * 2));
}

// =======================
// Setup Function
// =======================
void setup(void) {
    // Enable clock to GPIOA
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    // Configure PA5 as output
    gpio_init_output(LED_PORT, LED_PIN);
}

// =======================
// Main Loop
// =======================
int main(void) {
    setup();

    while (1) {
        ms_delay(1500);
        LED_PORT->ODR ^= (1 << LED_PIN); // Toggle LED
    }

    return 0;
}
