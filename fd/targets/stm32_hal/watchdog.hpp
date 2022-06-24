/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_STM32_HAL_WATCHDOG
#define FD_HDR_STM32_HAL_WATCHDOG
#include <stm32f1xx_hal_conf.h>

#ifdef HAL_WWDG_MODULE_ENABLED
class window_watchdog {
        WWDG_HandleTypeDef *watchdog;
    public:
        window_watchdog(WWDG_HandleTypeDef *watchdog): watchdog(watchdog) {

        }

        void refresh() {
            HAL_WWDG_Refresh(watchdog);
        }
    };
#endif


#endif //FD_HDR_STM32_HAL_WATCHDOG
