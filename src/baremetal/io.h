#ifndef IO_H
#define IO_H

#include "nucleof4.h"

/* Set GPIO to output */
void gpio_init_output(GPIO_TypeDef *port, uint32_t pin);

/* Set GPIO to input */
void gpio_init_input(GPIO_TypeDef *port, uint32_t pin);


#endif