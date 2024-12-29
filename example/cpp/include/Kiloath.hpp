#ifndef Kiloath_HPP
#define Kiloath_HPP

#include "Kiloath.d.hpp"

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
    
    void Kiloath_greeting(diplomat::capi::DiplomatStringView name, diplomat::capi::DiplomatWrite* write);
    
    
    void Kiloath_destroy(Kiloath* self);
    
    } // extern "C"
} // namespace capi
} // namespace

inline std::string Kiloath::greeting(std::string_view name) {
  std::string output;
  diplomat::capi::DiplomatWrite write = diplomat::WriteFromString(output);
  diplomat::capi::Kiloath_greeting({name.data(), name.size()},
    &write);
  return output;
}

inline const diplomat::capi::Kiloath* Kiloath::AsFFI() const {
  return reinterpret_cast<const diplomat::capi::Kiloath*>(this);
}

inline diplomat::capi::Kiloath* Kiloath::AsFFI() {
  return reinterpret_cast<diplomat::capi::Kiloath*>(this);
}

inline const Kiloath* Kiloath::FromFFI(const diplomat::capi::Kiloath* ptr) {
  return reinterpret_cast<const Kiloath*>(ptr);
}

inline Kiloath* Kiloath::FromFFI(diplomat::capi::Kiloath* ptr) {
  return reinterpret_cast<Kiloath*>(ptr);
}

inline void Kiloath::operator delete(void* ptr) {
  diplomat::capi::Kiloath_destroy(reinterpret_cast<diplomat::capi::Kiloath*>(ptr));
}


#endif // Kiloath_HPP
