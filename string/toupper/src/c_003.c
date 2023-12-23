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