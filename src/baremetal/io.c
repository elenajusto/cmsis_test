#include "io.h"

/* Set GPIO to output */
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

/* Set GPIO to input */
void gpio_init_input(GPIO_TypeDef *port, uint32_t pin){
    // 1. Clear mode bits
    port->MODER &= ~(0x3 << (pin * 2));
    
    // 2. Set mode to '00' (general purpose input)
    port->MODER |=  (0x0 << (pin * 2));

    // Optional: Output type = push-pull (0)
    port->OTYPER &= ~(1 << pin);

    // Optional: Output speed = high speed (11)
    port->OSPEEDR |= (0x3 << (pin * 2));

    // Optional: No pull-up, pull-down (00)
    port->PUPDR &= ~(0x3 << (pin * 2));
}