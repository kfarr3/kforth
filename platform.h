#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef PLATFORM_UNIX
#include "platform_unix.h"
#else
#error "No Platform Selected: Please see README for information on how to add a new platform"
#endif


#endif
/***   End Of File   ***/

