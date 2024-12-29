#ifndef Kiloath2_H
#define Kiloath2_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "diplomat_runtime.h"


#include "Kiloath2.d.h"






Kiloath2* Kiloath2_new(DiplomatStringView name);

void Kiloath2_greeting(Kiloath2* self, DiplomatWrite* write);


void Kiloath2_destroy(Kiloath2* self);





#endif // Kiloath2_H
