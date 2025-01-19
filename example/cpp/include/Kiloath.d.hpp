#ifndef Kiloath_D_HPP
#define Kiloath_D_HPP

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <optional>
#include "diplomat_runtime.hpp"


namespace diplomat {
namespace capi {
    struct Kiloath;
} // namespace capi
} // namespace

class Kiloath {
public:

  inline static std::string greeting(std::string_view name);

  inline static std::string greeting_u(std::string_view name);

  inline const diplomat::capi::Kiloath* AsFFI() const;
  inline diplomat::capi::Kiloath* AsFFI();
  inline static const Kiloath* FromFFI(const diplomat::capi::Kiloath* ptr);
  inline static Kiloath* FromFFI(diplomat::capi::Kiloath* ptr);
  inline static void operator delete(void* ptr);
private:
  Kiloath() = delete;
  Kiloath(const Kiloath&) = delete;
  Kiloath(Kiloath&&) noexcept = delete;
  Kiloath operator=(const Kiloath&) = delete;
  Kiloath operator=(Kiloath&&) noexcept = delete;
  static void operator delete[](void*, size_t) = delete;
};


#endif // Kiloath_D_HPP
