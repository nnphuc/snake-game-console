#ifndef UTILITY_H
#define UTILITY_H


#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <climits>
#include <ctime>
#include <cinttypes>

#include <iostream>
#include <sstream>
#include <fstream>
#include <istream>
#include <ostream>
#include <thread>
#include <mutex>
#include "keycode.h"

#define GAME_WIDTH 40
#define GAME_HEIGHT 15




#define min2(a,b) ({ __typeof__(a) __a=(a); __typeof__(b) __b=(b); __a<__b?__a:__b;})
#define max2(a,b) ({ __typeof__(a) __a=(a); __typeof__(b) __b=(b); __a>__b?__a:__b;})

wchar_t *toWchar_t(const char *c);

inline uint64_t now()
{
    uint32_t lo, hi;
    __asm__ __volatile__ (
      "xorl %%eax, %%eax\n"
      "cpuid\n"
      "rdtsc\n"
      : "=a" (lo), "=d" (hi)
      :
      : "%ebx", "%ecx" );
    return (uint64_t)hi << 32 | lo;
}

namespace std{
    string to_string(int x);
}

#endif // UTILITY_H
