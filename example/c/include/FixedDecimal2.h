#ifndef FixedDecimal2_H
#define FixedDecimal2_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "diplomat_runtime.h"


#include "FixedDecimal2.d.h"






FixedDecimal2* icu4x_FixedDecimal2_new_mv1(int32_t v);

void icu4x_FixedDecimal2_multiply_pow10_mv1(FixedDecimal2* self, int16_t power);

typedef struct icu4x_FixedDecimal2_to_string_mv1_result { bool is_ok;} icu4x_FixedDecimal2_to_string_mv1_result;
icu4x_FixedDecimal2_to_string_mv1_result icu4x_FixedDecimal2_to_string_mv1(const FixedDecimal2* self, DiplomatWrite* write);


void icu4x_FixedDecimal2_destroy_mv1(FixedDecimal2* self);





#endif // FixedDecimal2_H
