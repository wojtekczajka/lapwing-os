SHELL = /bin/sh
SUBDIRS = ping pong
ASMFLAGS = -f elf64
CFLAGS = -std=c99 -mcmodel=large -ffreestanding -fno-stack-protector -mno-red-zone -c
LDFLAGS = -nostdlib -T link.lds
OBJCOPYFLAGS = -O binary
OBJ = start.o main.o
LIB = ../lib/lib.a

all : user
	objcopy $(OBJCOPYFLAGS) user pingpong
	mkdir -p ../bin && cp pingpong ../bin/
	$(MAKE) subdirs

.PHONY : subdirs $(SUBDIRS)

subdirs : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@ clean all

user : $(OBJ)
	ld $(LDFLAGS) -o user $(OBJ) $(LIB)

%.o : %.asm
	nasm $(ASMFLAGS) $< -o $@

%.o : %.c
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f *.o user pingpong
	for subdir in $(SUBDIRS); do \
		$(MAKE) -C $$subdir clean; \
	done

