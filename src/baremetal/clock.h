#ifndef CLOCK_H
#define CLOCK_H

#include "nucleof4.h"

/* Setup System Clock */
void rcc_system_setup(void);

/* Setup GPIO Peripheral Clocks */
void rcc_peripheral_setup(void);

#endif