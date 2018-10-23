#--------------------------------------
# Set device, directories and programmer here
#--------------------------------------

# main file
TARGET = main

# directories
BIN = bin
INC = inc

# device parameters
DEVICE     = attiny85
CLOCK      = 8000000
PROGRAMMER = dragon_isp
LFUSE      = 0xE2
HFUSE      = 0xD5
EFUSE      = 0xfE

# AVR Toolchain
CC      = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude -c $(PROGRAMMER) -p $(DEVICE)


# Compilation options
CFLAGS  = -mmcu=$(DEVICE) -Os -Wall -std=c99 -DF_CPU=$(CLOCK) -I $(INC)/

#--------------------------------------
# No need to edit the below code
#--------------------------------------

# source files and object directory
SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, %.o, $(SOURCES))

all: $(TARGET).hex

$(TARGET).elf: $(OBJECTS)
	$(CC) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex $< $@

# generate object file
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) -c -o $@ $^ 

# remove build files
clean:
	@echo deteling $(wildcard *.o) $(TARGET).elf $(TARGET).hex Makefile.deps
	@rm *.o $(TARGET).elf $(TARGET).hex Makefile.deps

# flash to micro-controller
flash: $(TARGET).hex
	$(AVRDUDE) -U flash:w:$<

# set fuses
fuses:
	$(AVRDUDE) -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

# show fuses already set on micro-controller
show_fuses:
	$(AVRDUDE) -nt

# Optionally show how big the resulting program is 
size:  $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(DEVICE) $(TARGET).elf