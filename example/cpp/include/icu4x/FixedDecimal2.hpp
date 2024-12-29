#ifndef icu4x_FixedDecimal2_HPP
#define icu4x_FixedDecimal2_HPP

#include "FixedDecimal2.d.hpp"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <optional>
#include "../diplomat_runtime.hpp"


namespace icu4x {
namespace capi {
    extern "C" {
    
    icu4x::capi::FixedDecimal2* icu4x_FixedDecimal2_new_mv1(int32_t v);
    
    void icu4x_FixedDecimal2_multiply_pow10_mv1(icu4x::capi::FixedDecimal2* self, int16_t power);
    
    typedef struct icu4x_FixedDecimal2_to_string_mv1_result { bool is_ok;} icu4x_FixedDecimal2_to_string_mv1_result;
    icu4x_FixedDecimal2_to_string_mv1_result icu4x_FixedDecimal2_to_string_mv1(const icu4x::capi::FixedDecimal2* self, diplomat::capi::DiplomatWrite* write);
    
    
    void icu4x_FixedDecimal2_destroy_mv1(FixedDecimal2* self);
    
    } // extern "C"
} // namespace capi
} // namespace

inline std::unique_ptr<icu4x::FixedDecimal2> icu4x::FixedDecimal2::new_(int32_t v) {
  auto result = icu4x::capi::icu4x_FixedDecimal2_new_mv1(v);
  return std::unique_ptr<icu4x::FixedDecimal2>(icu4x::FixedDecimal2::FromFFI(result));
}

inline void icu4x::FixedDecimal2::multiply_pow10(int16_t power) {
  icu4x::capi::icu4x_FixedDecimal2_multiply_pow10_mv1(this->AsFFI(),
    power);
}

inline diplomat::result<std::string, std::monostate> icu4x::FixedDecimal2::to_string() const {
  std::string output;
  diplomat::capi::DiplomatWrite write = diplomat::WriteFromString(output);
  auto result = icu4x::capi::icu4x_FixedDecimal2_to_string_mv1(this->AsFFI(),
    &write);
  return result.is_ok ? diplomat::result<std::string, std::monostate>(diplomat::Ok<std::string>(std::move(output))) : diplomat::result<std::string, std::monostate>(diplomat::Err<std::monostate>());
}

inline const icu4x::capi::FixedDecimal2* icu4x::FixedDecimal2::AsFFI() const {
  return reinterpret_cast<const icu4x::capi::FixedDecimal2*>(this);
}

inline icu4x::capi::FixedDecimal2* icu4x::FixedDecimal2::AsFFI() {
  return reinterpret_cast<icu4x::capi::FixedDecimal2*>(this);
}

inline const icu4x::FixedDecimal2* icu4x::FixedDecimal2::FromFFI(const icu4x::capi::FixedDecimal2* ptr) {
  return reinterpret_cast<const icu4x::FixedDecimal2*>(ptr);
}

inline icu4x::FixedDecimal2* icu4x::FixedDecimal2::FromFFI(icu4x::capi::FixedDecimal2* ptr) {
  return reinterpret_cast<icu4x::FixedDecimal2*>(ptr);
}

inline void icu4x::FixedDecimal2::operator delete(void* ptr) {
  icu4x::capi::icu4x_FixedDecimal2_destroy_mv1(reinterpret_cast<icu4x::capi::FixedDecimal2*>(ptr));
}


#endif // icu4x_FixedDecimal2_HPP
