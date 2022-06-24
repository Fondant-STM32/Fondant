/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_FONDANT
#define FD_HDR_FONDANT

#include <fd/fondant_targets.hpp>

#include <fd/targets/base/core.hpp>




#if FONDANT_TARGET==FONDANT_TARGET_STM32_HAL
#include "./targets/stm32_hal/core.hpp"
#endif


#endif //FD_HDR_FONDANT


// TODO
// TODO MPU6050
// TODO OLED
// TODO HD44780