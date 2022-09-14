SHELL = /bin/sh
ASMFLAGS = -f elf64
CFLAGS = -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c
LDFLAGS = -nostdlib -T link.lds
OBJCOPYFLAGS = -O binary
OBJ = start.o main.o
LIB = ../lib/lib.a

all : user
	objcopy $(OBJCOPYFLAGS) user ls
	mkdir -p ../bin && cp ls ../bin/

user : $(OBJ)
	ld $(LDFLAGS) -o user $(OBJ) $(LIB)

%.o : %.asm
	nasm $(ASMFLAGS) $< -o $@

%.o : %.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f *.o ls* user*

