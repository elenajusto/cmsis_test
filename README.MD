# CMSIS Test

Welcome to CMSIS test. Here I am trying to get a more holistic understanding of MCU hardware and embedded architecture without relying on too much vendor-specific abstraction (i.e., HAL, CubeMX, etc) in hopes of being able to better jump acoss different processors.

## Architecture
Here is diagram showing how I am hoping to organise software architecture.

![alt text](https://github.com/elenajusto/cmsis_test/blob/main/docs/images/architecture.png "Architecture Diagram")

## CMSIS and Platform.io

![alt text](https://github.com/elenajusto/cmsis_test/blob/feature/io/docs/images/cmsis.png "CMSIS Diagram")

The CMSIS documentation says you need 4 files to use it, these are:
1. Startup File
2. System Configuration Files
3. Device Header File

Digging through the Platform.io header includes, I have located each one:
1. ".platformio/packages/framework-cmsis-stm32f4/Source/Templates/gcc/startup_stm32f401xe.S"
2. ".platformio/packages/framework-cmsis-stm32f4/Include/system_stm32f4xx.h"
3. ".platformio/packages/framework-cmsis-stm32f4/Source/Templates/system_stm32f4xx.c"
4. ".platformio/packages/framework-cmsis-stm32f4/Include/stm32f401xe.h"

So what are each of these files?

1. STM32F401xExx Devices vector table for GCC based toolchains. 
- The documentation says this is meant to contain "reset handler and exception vectors."

2. CMSIS Cortex-M4 Device System Source File for STM32F4xx devices.

3. CMSIS Cortex-M4 Device Peripheral Access Layer System Source File.
- The documentation says this is meant to contain "general device configuration (i.e. for clock and BUS setup)."

4. CMSIS STM32F401xE Device Peripheral Access Layer Header File.
- The documentation says this is meant to contain "gives access to processor core and all peripherals."
