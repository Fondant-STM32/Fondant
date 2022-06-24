/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_FONDANT_TARGETS
#define FD_HDR_FONDANT_TARGETS

#define FONDANT_TARGET_STM32_HAL 10


#ifdef USE_HAL_DRIVER

#define FONDANT_TARGET FONDANT_TARGET_STM32_HAL
#define FONDANT_INTERRUPTS
#include "stm32f1xx_hal.h"

#ifdef HAL_SPI_MODULE_ENABLED
#define FONDANT_HW_SPI
#endif

#ifdef HAL_I2C_MODULE_ENABLED
#define FONDANT_HW_I2C
#endif

#ifdef HAL_UART_MODULE_ENABLED
#define FONDANT_HW_UART
#endif


#endif


#ifndef FONDANT_TARGET
#error "Kan target board niet vinden"
#endif

#endif //FD_HDR_FONDANT_TARGETS
