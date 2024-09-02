# Target name of final executable
TARGET = bare_metal

# DEBUG
DEBUG = 1

# Directories
BUILD_DIR = build
SRC_BASE_DIR = src
MU_BASE_DIR = mu
STARTUP_DIR = $(MU_BASE_DIR)/startup
LSCRIPT_DIR := $(MU_BASE_DIR)/linker
CMSIS_DIR = $(MU_BASE_DIR)/cmsis

SRC_FILES := $(wildcard  *.c) \
						$(wildcard $(MU_BASE_DIR)/*.c) \
						$(wildcard $(STARTUP_DIR)/*.c) \
						$(wildcard $(SRC_BASE_DIR)/*.c) \
						$(wildcard $(SRC_BASE_DIR)/systick/*.c)


SRC_DIRS := $(dir $(SRC_FILES))
OBJ_FILES := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRC_FILES))
OBJ_DIRS := $(dir $(OBJ_FILES))

#VPATH := $(SRC_DIRS)

$(info SRC_FILES is $(SRC_FILES))
$(info SRC_DIRS is $(SRC_DIRS))
$(info OBJ_FILES is $(OBJ_FILES))
$(info OBJ_DIRS is $(OBJ_DIRS))

#Directory stuff
MKDIR_P := mkdir -p


#Include Directories
INC_DIR = I$(LSCRIPT_DIR) \
					-I$(MU_BASE_DIR) \
					-I$(STARTUP_DIR) \
					-I$(CMSIS_DIR) \
					-I$(SRC_BASE_DIR)/systick

$(info INC_DIR is $(INC_DIR))

# Tools to use
CROSS_COMPILE = arm-none-eabi-
CC = $(CROSS_COMPILE)gcc
LD = $(CROSS_COMPILE)gcc
CP = $(CROSS_COMPILE)objcopy
SZ = $(CROSS_COMPILE)size

# GCC FLAGS
CPU = -mcpu=cortex-m7
FPU = -mfpu=fpv5-sp-d16
FLOAT-ABI = -mfloat-abi=hard
MCU = $(CPU) -mthumb $(FPU) $(FLOAT-ABI)
GCC_STANDARD = -std=c99
#DEPENDECY = -MMD

# Additional DEBUG Flag
OPT = -O3
DEBUG_FLAG = -Wno-unused -Wextra -pedantic

# -H print the recursive searh path
# -M prints which headerfiles was included
ifeq ($(DEBUG), 1)
OPT = -O0
DEBUG_FLAG += -H -g3 -gdwarf-2
endif

# Compiler Flags
#CFLAGS += -ffreestanding
CFLAGS += $(MCU) $(DEBUG_FLAG) $(OPT) $(GCC_STANDARD) $(DEPENDECY)\
					-$(INC_DIR) \
					-ffreestanding -ffunction-sections -nostdlib \
					-fdata-sections


# Linker Script
LSCRIPT=$(LSCRIPT_DIR)/mem.ld
$(info Linker is $(LSCRIPT))

# Libs for Linker
# gonna use -nostdlib and pick and choose desired libs
# -lc has malloc but need to implement _sbrk
LIBS = -lc
# Linker Flags
LDFLAGS = -T$(LSCRIPT)  $(MCU) -nostdlib $(LIBS) -Wl,-Map=$(BUILD_DIR)/$(TARGET).map -Wl,--cref -Wl,--gc-sections


.PHONY: clean nuke list all directories

all: $(BUILD_DIR)/$(TARGET).bin

directories: $(BUILD_DIR)

$(BUILD_DIR):
	${MKDIR_P} $(OBJ_DIRS)


$(BUILD_DIR)/$(TARGET).bin: $(BUILD_DIR)/$(TARGET).elf | directories
	$(CP) -O binary $< $@

$(BUILD_DIR)/$(TARGET).elf: $(OBJ_FILES) | directories
	$(LD)  $(LDFLAGS) -o $@ $^
	$(SZ) $@


$(BUILD_DIR)/%.o: %.c | directories
	$(CC) $(CFLAGS)  -c $< -o $@

-include $(OBJ_FILES:.o=.d)

list:
	@$(MAKE) -pRrq -f $(lastword $(MAKEFILE_LIST)) : 2>/dev/null | awk -v RS= -F: '/^# File/,/^# Finished Make data base/ {if ($$1 !~ "^[#.]") {print $$1}}' | sort | egrep -v -e '^[^[:alnum:]]' -e '^$@$$'

nuke:
	-rm -rf *.o *.d *.elf *.bin *.hex *.map $(BUILD_DIR)

flash:
	st-flash write $(BUILD_DIR)/$(TARGET).bin 0x8000000

