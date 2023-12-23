#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

extern void func_toupper(char *dst, const char *src, int len);

int main(int argc, char * argv[])
{
    char *src = "RWAGeNIsfdHOGJBALdfsKVNXesdfUEYORdsfEEhQSDSDFYKTUKKDFsSfDFDmnVZdsfDSVBFPRQNKNFASRW";

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