SHELL = /bin/sh
ASMFLAGS = -f elf64
ARFLAGS = rcs
CFLAGS = -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c
OBJ = print.o syscall.o task.o lib.o
TESTOBJ = test/test.o
LIB = lib.a

all : $(OBJ)
	ar $(ARFLAGS) $(LIB) $(OBJ)

%.o : %.asm
	nasm $(ASMFLAGS) $< -o $@

%.o : %.c
	gcc $(CFLAGS) $< -o $@

.PHONY: test

test : $(LIB)
	$(MAKE) all
	gcc -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -o test/test test/test.c
	./test/test

clean:
	rm -f *.o *.a /test/test
