CC = gcc
STRIP = strip
CFLAGS = -m32

OBJECTS = main.o platform_unix.o dictionary_1.o kforth.o


kforth : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -Wl,-Map=kforth.map -o kforth
	$(STRIP) --strip-unneeded kforth


unix : 
	PFLAGS=-DPLATFORM_UNIX make kforth


.PHONY : clean

clean:
	rm -f *.o kforth *.map
	@echo "Project cleaned"

%.o : %.c
ifeq ($(PFLAGS),)
	@echo "Make initiated incorrectly, please see README.  Expected 'make unix' or the like"
	exit -42
else
	$(CC) $(PFLAGS) $(CFLAGS) -c $<
endif

