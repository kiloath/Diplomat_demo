#ifndef icu4x_FixedDecimal2_D_HPP
#define icu4x_FixedDecimal2_D_HPP

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <optional>
#include "../diplomat_runtime.hpp"

namespace icu4x {
namespace capi { struct FixedDecimal2; }
class FixedDecimal2;
}


namespace icu4x {
namespace capi {
    struct FixedDecimal2;
} // namespace capi
} // namespace

namespace icu4x {
class FixedDecimal2 {
public:

  inline static std::unique_ptr<icu4x::FixedDecimal2> new_(int32_t v);

  inline void multiply_pow10(int16_t power);

  inline diplomat::result<std::string, std::monostate> to_string() const;

  inline const icu4x::capi::FixedDecimal2* AsFFI() const;
  inline icu4x::capi::FixedDecimal2* AsFFI();
  inline static const icu4x::FixedDecimal2* FromFFI(const icu4x::capi::FixedDecimal2* ptr);
  inline static icu4x::FixedDecimal2* FromFFI(icu4x::capi::FixedDecimal2* ptr);
  inline static void operator delete(void* ptr);
private:
  FixedDecimal2() = delete;
  FixedDecimal2(const icu4x::FixedDecimal2&) = delete;
  FixedDecimal2(icu4x::FixedDecimal2&&) noexcept = delete;
  FixedDecimal2 operator=(const icu4x::FixedDecimal2&) = delete;
  FixedDecimal2 operator=(icu4x::FixedDecimal2&&) noexcept = delete;
  static void operator delete[](void*, size_t) = delete;
};

} // namespace
#endif // icu4x_FixedDecimal2_D_HPP
