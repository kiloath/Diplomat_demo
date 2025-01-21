#pragma execution_character_set(push, "utf-8")
#define UTF8

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "include/Kiloath.h"
#include "include/kiloath2.h"

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

int main(int argc, char *argv[]) {
    greeting("程式傳說");
    greeting2("程式傳說2");
    Kiloath2* kiloath;
    greeting3(&kiloath, "程式傳說3");
}
