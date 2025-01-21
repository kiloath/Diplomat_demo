#pragma once
// #include "include/Kiloath.h"
// #include "include/kiloath2.h"

#ifdef DIPLOMAT_EXAMPLE_EXPORT
  #define DIPLOMAT_EXAMPLE_API __declspec(dllexport)
#else
  #define DIPLOMAT_EXAMPLE_API __declspec(dllimport)
#endif

DIPLOMAT_EXAMPLE_API void greeting(const char* name);
DIPLOMAT_EXAMPLE_API void greeting2(const char* name);
// void greeting3(Kiloath2 **kiloath, const char* name);