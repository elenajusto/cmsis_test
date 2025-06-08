#ifndef NUCLEOF4_H
#define NUCLEOF4_H

#include "stm32f4xx.h"

/* 
* Definitions for the STM32F401RE Nucleo Board 
*/

/* 
* Onboard Peripherals 
*/
#define LED_PORT GPIOA
#define LED_PIN  5

#define BUTTON_PORT GPIOC
#define BUTTON_PIN 13

/* 
* Right Side 
*/
#define D0_PORT GPIOA   // UART2_RX
#define D0_PIN 3

#define D1_PORT GPIOA   // UART2_TX
#define D1_PIN 2

#define D2_PORT GPIOA   // UART1_RX
#define D2_PIN 10

#define D3_PORT GPIOB   // SPI1_SCLK, I2C_SDA
#define D3_PIN 3

#define D4_PORT GPIOB   // SPI1_MOSI
#define D4_PIN 5

#define D5_PORT GPIOB   // SPI1_MISO, I2C3_SDA
#define D5_PIN 4

#define D6_PORT GPIOB   // SPI2_SCLK, I2C_SCL
#define D6_PIN 10

#define D7_PORT GPIOA   // I2C3_SCL
#define D7_PIN 8

#define D8_PORT GPIOA   // UART1_TX
#define D8_PIN 9

#define D9_PORT GPIOC   //UART6_RX
#define D9_PIN 7

#define D10_PORT GPIOB  // UART1_TX, I2C1_SCL
#define D10_PIN 6

#define D11_PORT GPIOA  // ADC1/7, SPI1_MOSI
#define D11_PIN 7

#define D12_PORT GPIOA  // ADC1/6, SPI1_MISO
#define D12_PIN 6

#define D13_PORT GPIOA  // ADC1/5, SPI1_SCLK, LED1
#define D13_PIN 5

#define D14_PORT GPIOB  // SPI2_SSEL, I2C1_SDA
#define D14_PIN 9

#define D15_PORT GPIOB  // I2C1_SCL
#define D15_PIN 8

/* 
* Left Side 
*/
#define A5_PORT GPIOC   // ADC1/10
#define A5_PIN 0

#define A4_PORT GPIOC   // ADC1/11
#define A4_PIN 1

#define A3_PORT GPIOB   // ADC1/8
#define A3_PIN 0

#define A2_PORT GPIOA   // ADC1/4
#define A2_PIN 4

#define A1_PORT GPIOA   // ADC1/1
#define A1_PIN 1

#define A0_PORT GPIOA   // ADC1/0
#define A0_PIN 0

#endif