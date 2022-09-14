SHELL = /bin/sh
SUBDIRS = lib loader kernel user1 totalmem ls clear pingpong
.PHONY : all $(SUBDIRS)

all : $(SUBDIRS)

$(SUBDIRS) :
	$(MAKE) -C $@ clean all
	

clean :
	for subdir in $(SUBDIRS); do \
		$(MAKE) -C $$subdir clean; \
	done


