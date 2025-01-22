#pragma once

#ifdef _WIN32
  #define DIPLOMAT_EXAMPLE_API __declspec(dllexport)
#else
  #define DIPLOMAT_EXAMPLE_API
#endif

DIPLOMAT_EXAMPLE_API void greeting(const char* name);
DIPLOMAT_EXAMPLE_API void greeting2(const char* name);
// DIPLOMAT_EXAMPLE_API void greeting3(Kiloath2 **kiloath, const char* name);
