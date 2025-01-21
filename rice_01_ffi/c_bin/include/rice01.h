#pragma once

#include <vector>
#include <string>


#ifdef _WIN32
  #define RICE01_EXPORT __declspec(dllexport)
#else
  #define RICE01_EXPORT
#endif

RICE01_EXPORT void rice01();
RICE01_EXPORT void rice01_print_vector(const std::vector<std::string> &strings);
