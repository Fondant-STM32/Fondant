/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_I2C
#define FD_HDR_I2C

#include <fd/fondant_targets.hpp>

#if FONDANT_TARGET == FONDANT_TARGET_STM32_HAL

#ifndef FONDANT_HW_I2C
#error "I2C is niet ingesteld STM32IDE. Stel tenminste 1 I2C-bus in"
#endif

#include <fd/targets/stm32_hal/i2c.hpp>

#else
#error "Geen I2C implementatie gevonden voor target"
#endif

#endif //FD_HDR_I2C
