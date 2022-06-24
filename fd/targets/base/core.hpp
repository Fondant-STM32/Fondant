/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_BASE_CORE
#define FD_HDR_BASE_CORE

namespace fd {
	/**
	 * Standaardfunctie, laat de microcontroller een gegeven aantal ms wachten.
	 * @param ms Het aantal ms
	 */
    void sleep(long ms);

    /**
     * Functie om de microcontroller (via software) opnieuw op te starten.
     * Na het aanroepen van deze functie zal de main() volledig opnieuw aangeroepen worden.
     */
    void software_reset();

    void none();
}

#endif //FD_HDR_BASE_CORE
