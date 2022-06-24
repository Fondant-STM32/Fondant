/*
 *
 * Copyright Niels Post 2022.
 * Distributed under the Boost Software License, Version 1.0.
 * (See accompanying file LICENSE or copy at
 * https://www.boost.org/LICENSE_1_0.txt)
 *
*/
#ifndef FD_HDR_FONDANT_MAIN
#define FD_HDR_FONDANT_MAIN

extern int fd_main();

extern "C" int fd_main_caller() {
    return fd_main();
}


#endif //FD_HDR_FONDANT_MAIN

