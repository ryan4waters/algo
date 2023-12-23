CC = gcc
CFLAGS = -static -O2 -ftree-vectorize
# -static is used so that the executable file does not depend on external libraries, so that the data obtained is more accurate.

all : c_001 c_002 c_003 c_004 c_005 c_006
.PHONY : all

c_001 : main.c c_001.c
	$(CC) -o c_001 main.c c_001.c $(CFLAGS)

c_002 : main.c c_002.c
	$(CC) -o c_002 main.c c_002.c $(CFLAGS)

c_003 : main.c c_003.c
	$(CC) -o c_003 main.c c_003.c $(CFLAGS)

c_004 : main.c c_004.c
	$(CC) -o c_004 main.c c_004.c $(CFLAGS)

c_005 : main.c c_005.c
	$(CC) -o c_005 main.c c_005.c $(CFLAGS)

c_006: main.c c_006.c
	$(CC) -o c_006 main.c c_006.c $(CFLAGS)
