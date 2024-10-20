#ifndef GLOBAL_H
#define GLOBAL_H

typedef signed char s8;
typedef signed short s16;
typedef signed int s32;
typedef signed long long s64;
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef float f32;
typedef u32 uintptr_t;

#define true 1
#define false 0
#define bool s32

#define NULL 0

double fabsf(double f);
#pragma intrinsic(fabsf)

#include "variables.h"
#include "macros.h"

#endif
