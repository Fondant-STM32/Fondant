/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_SPI
#define FD_HDR_SPI

#include <fd/fondant_targets.hpp>


#if FONDANT_TARGET == FONDANT_TARGET_STM32_HAL

#ifndef FONDANT_HW_SPI
#error "SPI is niet ingesteld STM32IDE. Stel tenminste 1 SPI-bus in"
#endif

#include "./targets/stm32_hal/spi.hpp"

#else
#error "Geen SPI implementatie gevonden voor target"
#endif


#endif //FD_HDR_SPI
