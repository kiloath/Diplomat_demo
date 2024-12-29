#ifndef Kiloath_H
#define Kiloath_H

#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include "diplomat_runtime.h"


#include "Kiloath.d.h"






void Kiloath_greeting(DiplomatStringView name, DiplomatWrite* write);


void Kiloath_destroy(Kiloath* self);





#endif // Kiloath_H
