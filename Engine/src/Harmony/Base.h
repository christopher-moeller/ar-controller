#pragma once

#include "Harmony/Log.h"

#include <iostream>
#include <string>
#include <sstream>
#include <functional>
#include <utility>


#ifdef AR_DEBUG
    #define HY_ASSERT(x, ...) { if(!(x)) { HY_ERROR("Assertion Failed {0}", __VA_ARGS__); __builtin_debugtrap(); } }
    #define HY_CORE_ASSERT(x, ...) { if(!(x)) { HY_CORE_ERROR("Assertion Failed {0}", __VA_ARGS__); __builtin_debugtrap(); } }
#else
    #define HY_ASSERT(x, ...)
    #define HYCORE__ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)
