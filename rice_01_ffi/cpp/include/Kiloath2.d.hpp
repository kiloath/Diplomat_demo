#ifndef Kiloath2_D_HPP
#define Kiloath2_D_HPP

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <optional>
#include "diplomat_runtime.hpp"


namespace diplomat {
namespace capi {
    struct Kiloath2;
} // namespace capi
} // namespace

class Kiloath2 {
public:

  inline static std::unique_ptr<Kiloath2> new_(std::string_view name);

  inline static std::unique_ptr<Kiloath2> new_u(std::string_view name);

  inline std::string greeting();

  inline const diplomat::capi::Kiloath2* AsFFI() const;
  inline diplomat::capi::Kiloath2* AsFFI();
  inline static const Kiloath2* FromFFI(const diplomat::capi::Kiloath2* ptr);
  inline static Kiloath2* FromFFI(diplomat::capi::Kiloath2* ptr);
  inline static void operator delete(void* ptr);
private:
  Kiloath2() = delete;
  Kiloath2(const Kiloath2&) = delete;
  Kiloath2(Kiloath2&&) noexcept = delete;
  Kiloath2 operator=(const Kiloath2&) = delete;
  Kiloath2 operator=(Kiloath2&&) noexcept = delete;
  static void operator delete[](void*, size_t) = delete;
};


#endif // Kiloath2_D_HPP
