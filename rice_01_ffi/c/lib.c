#define UTF8

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "lib.h"
void greeting(const char* name)
{
    #define OUTPUT_SIZE 100
    char output[OUTPUT_SIZE];
    DiplomatWrite out = diplomat_simple_write(output, OUTPUT_SIZE);
    #ifdef UTF8
    Kiloath_greeting_u ( (DiplomatStringView){.data = name, .len = strlen(name)}, &out);
    #else
    Kiloath_greeting( (DiplomatStringView){.data = name, .len = strlen(name)}, &out);
    #endif
    output[out.len] = '\0';
    printf("%s\n", output);
}
void greeting2(const char* name)
{
    #define OUTPUT_SIZE 100
    char output[OUTPUT_SIZE];
    DiplomatWrite out = diplomat_simple_write(output, OUTPUT_SIZE);
    #ifdef UTF8
    Kiloath2* kiloath = Kiloath2_new_u((DiplomatStringView){.data = name, .len = strlen(name)});
    #else
    Kiloath2* kiloath = Kiloath2_new((DiplomatStringView){.data = name, .len = strlen(name)});
    #endif
    Kiloath2_greeting( kiloath, &out);
    output[out.len] = '\0';
    printf("%s\n", output);
}
void greeting3(Kiloath2 **kiloath, const char* name)
{
    #define OUTPUT_SIZE 100
    char output[OUTPUT_SIZE];
    DiplomatWrite out = diplomat_simple_write(output, OUTPUT_SIZE);
    #ifdef UTF8
    *kiloath = Kiloath2_new_u((DiplomatStringView){.data = name, .len = strlen(name)});
    #else
    *kiloath = Kiloath2_new((DiplomatStringView){.data = name, .len = strlen(name)});
    #endif
    Kiloath2_greeting( *kiloath, &out);
    output[out.len] = '\0';
    printf("%s\n", output);
}