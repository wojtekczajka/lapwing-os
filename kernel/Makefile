SHELL = /bin/sh
ASMFLAGS = -f elf64
CFLAGS = -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c
LDFLAGS = -nostdlib -T link.lds
OBJCOPYFLAGS = -O binary
OBJ = kernela.o main.o trapa.o trap.o liba.o print.o debug.o memory.o process.o syscall.o lib.o keyboard.o file.o

all : kernel
	objcopy $(OBJCOPYFLAGS) kernel kernel.bin
	mkdir -p ../bin && cp kernel.bin ../bin/

kernel : $(OBJ)
	ld $(LDFLAGS) -o kernel $(OBJ)

%.o : %.asm
	nasm $(ASMFLAGS) $< -o $@

%.o : %.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f *.o kernel *.bin

