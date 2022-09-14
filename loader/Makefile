SHELL = /bin/sh
ASM_OBJ_FLAGS = -f elf64
ASM_BIN_FLAGS = -f bin
CFLAGS = -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c
LDFLAGS = -nostdlib -T link.lds
OBJCOPYFLAGS = -O binary
OBJ = entry.o main.o lib.o print.o debug.o file.o

all : entry loader.bin 
	objcopy $(OBJCOPYFLAGS) entry entry.bin
	dd if=entry.bin >> loader.bin
	dd if=loader.bin of=../os.img bs=512 count=15 seek=1 conv=notrunc
	
entry : $(OBJ)
	ld $(LDFLAGS) -o entry $(OBJ)

%.bin : %.asm
	nasm $(ASM_BIN_FLAGS) $< -o $@

%.o : %.asm
	nasm $(ASM_OBJ_FLAGS) $< -o $@

%.o : %.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f *.o *.bin entry

