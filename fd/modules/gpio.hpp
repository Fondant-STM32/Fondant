/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_GPIO
#define FD_HDR_GPIO

#include "fd/util/fondant_targets.hpp"




#if FONDANT_TARGET == FONDANT_TARGET_STM32_HAL
#include "fd/targets/stm32_hal/gpio.hpp"
#else
#error "Geen GPIO implementatie gevonden voor target"
#endif


#endif //FD_HDR_GPIO
