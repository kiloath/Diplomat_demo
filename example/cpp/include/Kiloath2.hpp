#ifndef Kiloath2_HPP
#define Kiloath2_HPP

#include "Kiloath2.d.hpp"

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <memory>
#include <optional>
#include "diplomat_runtime.hpp"


namespace diplomat {
namespace capi {
    extern "C" {
    
    diplomat::capi::Kiloath2* Kiloath2_new(diplomat::capi::DiplomatStringView name);
    
    void Kiloath2_greeting(diplomat::capi::Kiloath2* self, diplomat::capi::DiplomatWrite* write);
    
    
    void Kiloath2_destroy(Kiloath2* self);
    
    } // extern "C"
} // namespace capi
} // namespace

inline std::unique_ptr<Kiloath2> Kiloath2::new_(std::string_view name) {
  auto result = diplomat::capi::Kiloath2_new({name.data(), name.size()});
  return std::unique_ptr<Kiloath2>(Kiloath2::FromFFI(result));
}

inline std::string Kiloath2::greeting() {
  std::string output;
  diplomat::capi::DiplomatWrite write = diplomat::WriteFromString(output);
  diplomat::capi::Kiloath2_greeting(this->AsFFI(),
    &write);
  return output;
}

inline const diplomat::capi::Kiloath2* Kiloath2::AsFFI() const {
  return reinterpret_cast<const diplomat::capi::Kiloath2*>(this);
}

inline diplomat::capi::Kiloath2* Kiloath2::AsFFI() {
  return reinterpret_cast<diplomat::capi::Kiloath2*>(this);
}

inline const Kiloath2* Kiloath2::FromFFI(const diplomat::capi::Kiloath2* ptr) {
  return reinterpret_cast<const Kiloath2*>(ptr);
}

inline Kiloath2* Kiloath2::FromFFI(diplomat::capi::Kiloath2* ptr) {
  return reinterpret_cast<Kiloath2*>(ptr);
}

inline void Kiloath2::operator delete(void* ptr) {
  diplomat::capi::Kiloath2_destroy(reinterpret_cast<diplomat::capi::Kiloath2*>(ptr));
}


#endif // Kiloath2_HPP
