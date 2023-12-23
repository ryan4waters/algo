# How fast toupper is?

## Intro

When coding or practicing algorithm questions, you may encounter scenarios where a string is converted to uppercase or lowercase. Different algorithms have different execution efficiencies. This article lists six implementation methods and discusses ways to improve efficiency.

## Functions

For the sake of comparison effectiveness, I control the following points:

1. Each version of GCC interprets `-O3` differently, and it is rare to see applications compiled using `-O3`, so `-O3` is not tested.
2. Make sure all executable files are compiled with the same version of GCC (9.4.0)
3. The number of loops is 20,000,000: The word running time of `func_toupper` is very short, and the number obtained by `time` is close to 0. Hence the "zoom in" action.
4. The method of using `time` to obtain performance data is slightly crude, and the results are affected by various factors: other processes, interruptions, and system overhead. This also makes the result of `time` change every time. If the system is not very busy, then the error of this value is acceptable. On the contrary, this imprecise value may lead to errors in judgment.

The main function and six implementation algorithms are shown below:

### main function

```c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

extern void func_toupper(char *dst, const char *src, int len);

int main(int argc, char * argv[])
{
    char *src = "RWAGeNIZDGsfdHOGJBAhrsLdfsKVNXesdMNBCfUEYORvxgdsdmxbmsfEEhQSfdgCDSkxDFYKTUKKDKFFsSfDFDmnVZdsfKLDSVBFPRQNKNFASRW";

    char dst[256];

    if (argc != 2) {
        printf("Usage: char_conv [times]\n");
        return -1;
    }
    int times = atoi(argv[1]);
    for (int i = 0; i< times; ++i) {
        func_toupper(dst, src, strlen(src));
    }

    (void)dst;
    return 0;
}
```



### c lib

Call the C standard library function to traverse the conversion by characters.

```c
/*1.c lib*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void func_toupper(char *dst, const char *src, int len)
{
    for (int i = 0; i < len; ++i) {
        *dst++ = toupper(src[i]);
    }
    *dst = 0;
}
```



### sub

Subtract 32 from a lowercase ASCII character to get its corresponding uppercase character.

```c
/*2.sub*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void func_toupper(char *dst, const char *src, int len)
{
    unsigned char ch;
    for (int i = 0; i < len; ++i) {
        ch = src[i];
        *dst++ = (ch >= 'a' && ch <= 'z') ? (ch - 32) : ch;
    }
    *dst = 0;
}
```



### xor

xor calculation with 0x20.

```c
/*3.xor*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void func_toupper(char *dst, const char *src, int len)
{
    unsigned char ch;
    for (int i = 0; i < len; ++i) {
        ch = src[i];
        *dst++ = (ch >= 'a' && ch <= 'z') ? ch^0x20 : ch;
    }
    *dst = 0;
}
```



### query table

The ASCII table defines a total of 127 characters, which allows us to define a constant array in the same order as the ASCII table, and the values of the array correspond to their subscripts. Then, change the element value corresponding to the a-z position (0x61-0x7a) into uppercase characters. In this way, uppercase conversion becomes directly reading the value by position.

```c
/*4.query table*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

static const char uppertable[] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9,
    0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
};

void func_toupper(char *dst, const char *src, int len)
{
    for (int i = 0; i < len; ++i) {
        *dst++ = uppertable[(unsigned char)src[i]];
    }
    *dst = 0;
}
```



### int

Take advantage of CPU Cache capabilities. Take the string modulo 4 and calculate the remainder according to the table lookup method.

```c
/*5.int*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

static const char uppertable[] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9,
    0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
};

void func_toupper(char *dst, const char *src, int len)
{
    int i;
    uint32_t eax, ebx;
    const uint8_t* ustr = (const uint8_t*)src;
    const int leftover = len % 4;
    const int imax = len / 4;
    const uint32_t* s = (const uint32_t*)src;
    uint32_t* d = (uint32_t*)dst;
    for (int i = 0; i != imax; ++i) {
        eax = s[i];
        // http://azo;;ionmonkey.com/qed/asmexample.html
        ebx = (0x7f7f7f7fu & eax) + 0x05050505u;
        ebx = (0x7f7f7f7fu & ebx) + 0x1a1a1a1au;
        ebx = ((ebx & ~eax) >> 2) & 0x20202020u;
        *d++ = eax - ebx;
    }

    i = imax * 4;
    dst = (char*)d;
    switch (leftover) {
        case 3: *dst++ = (char)uppertable[ustr[i++]];
        case 2: *dst++ = (char)uppertable[ustr[i++]];
        case 1: *dst++ = (char)uppertable[ustr[i]];
        case 0: *dst = '\0';
    }
}
```



### int64

For the currently used CPU, its cache_line is 64 byte, so method 5 is further revised to the cache_line method.

```c
/*6.int64*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>

static const char uppertable[] = {
    0x0, 0x1, 0x2, 0x3, 0x4, 0x5, 0x6, 0x7, 0x8, 0x9,
    0xA, 0xB, 0xC, 0xD, 0xE, 0xF, 0x10, 0x11, 0x12, 0x13,
    0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D,
    0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27,
    0x28, 0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31,
    0x32, 0x33, 0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x3A, 0x3B,
    0x3C, 0x3D, 0x3E, 0x3F, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x5B, 0x5C, 0x5D, 0x5E, 0x5F, 0x60, 0x41, 0x42, 0x43, 0x44, 0x45,
    0x46, 0x47, 0x48, 0x49, 0x4A, 0x4B, 0x4C, 0x4D, 0x4E, 0x4F,
    0x50, 0x51, 0x52, 0x53, 0x54, 0x55, 0x56, 0x57, 0x58, 0x59,
    0x5A, 0x7B, 0x7C, 0x7D, 0x7E, 0x7F
};

void func_toupper(char *dst, const char *src, int len)
{
    int i;
    uint64_t eax, ebx;
    const uint8_t* ustr = (const uint8_t*)src;
    const int leftover = len % 8;
    const int imax = len / 8;
    const uint64_t* s = (const uint64_t*)src;
    uint64_t* d = (uint64_t*)dst;
    for (int i = 0; i != imax; ++i) {
        eax = s[i];
        // http://azo;;ionmonkey.com/qed/asmexample.html
        ebx = (0x7f7f7f7f7f7f7f7fu & eax) + 0x0505050505050505u;
        ebx = (0x7f7f7f7f7f7f7f7fu & ebx) + 0x1a1a1a1a1a1a1a1au;
        ebx = ((ebx & ~eax) >> 2) & 0x2020202020202020u;
        *d++ = eax - ebx;
    }

    i = imax * 4;
    dst = (char*)d;
    switch (leftover) {
        case 7: *dst++ = (char)uppertable[ustr[i++]];
        case 6: *dst++ = (char)uppertable[ustr[i++]];
        case 5: *dst++ = (char)uppertable[ustr[i++]];
        case 4: *dst++ = (char)uppertable[ustr[i++]];
        case 3: *dst++ = (char)uppertable[ustr[i++]];
        case 2: *dst++ = (char)uppertable[ustr[i++]];
        case 1: *dst++ = (char)uppertable[ustr[i]];
        case 0: *dst = '\0';
    }
}
```



## Result

All results below are in seconds.

| Function    |   -O0   |  -O1  |  -O2  |
| :---------- |  :---:  | :---: | :---: |
| c function  |  18.888 | 5.219 | 4.939 |
| sub         |  18.173 | 5.516 | 5.842 |
| xor         |  18.140 | 6.362 | 6.291 |
| query table |  14.080 | 3.950 | 4.711 |
| int         |  7.218  | 2.601 | 2.441 |
| int64       |  4.073  | 1.530 | 1.767 |

The trend of the 3 sets of data is the same. For this small program, the optimization effects of `-O1` and `-O2` are the same, and the running time of each version of the use case is very close.

We then use the `-ftree-vectorize` option in GCC to optimize execution through automatic vectorization. Compile the above 6 methods again and get the following comparative test results:

| Function    |  -O2  | -O2 -ftree-vectorize |
| :---------- | :---: | :------------------: |
| c function  | 4.939 |         5.092        |
| sub         | 5.842 |         0.696        |
| xor         | 6.291 |         0.716        |
| query table | 4.711 |         4.463        |
| int         | 2.441 |         0.834        |
| int64       | 1.767 |         0.748        |

It can be seen that the vectorization version has the greatest benefit in the subtraction and xor operation versions, directly beating all previous versions.