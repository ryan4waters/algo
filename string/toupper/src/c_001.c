/*1.c function*/
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