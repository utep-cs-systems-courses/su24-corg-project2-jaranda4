# Compiler and flags
CC = msp430-elf-gcc
CFLAGS = -mmcu=msp430g2553 -I./h -I./timerLib

# Source files
SRCS = p1_interrupt_handler.c led.c switches.c buttonMain.c state_machine.c buzzer.c
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = project.elf

# Default rule
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -L./timerLib -lTimer

# Compile source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Load target to program the MSP430
load: $(TARGET)
	/Applications/ti/uniflash_8.7.0/deskdb/content/TICloudAgent/osx/ccs_base/DebugServer/bin/DSLite flash --config /Users/javi1/msp430-m1/MSP430G2553.ccxml -f $(TARGET)

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)
