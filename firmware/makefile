
DEFAULT_TARGET = main
TARGET = $(DEFAULT_TARGET)

LD_SCRIPT = stm32F334K6TX_mem_map.ld

MCU = -mcpu=cortex-m4

TOOLCHAIN   = arm-none-eabi
COMPILER    = $(TOOLCHAIN)-gcc
OBJECT_COPY = $(TOOLCHAIN)-objcopy
OBJECT_DUMP = $(TOOLCHAIN)-objdump
OBJECT_SIZE = $(TOOLCHAIN)-size

SRC_DIR       = ./src/
INC_DIR       = ./inc/
CMSIS_DEV_DIR = ./CMSIS/Device/
CMSIS_INC_DIR = ./CMSIS/Include/
BIN_DIR       = ./bin/

OPTIONS += $(MCU)
OPTIONS += -Os
OPTIONS += -mfloat-abi=softfp
OPTIONS += -mfpu=fpv4-sp-d16
OPTIONS += --specs=nosys.specs
OPTIONS += -nostdlib
OPTIONS += -fno-exceptions
OPTIONS += -mthumb
OPTIONS += -Wall
OPTIONS += -g

ASM_FLAGS += -c
ASM_FLAGS += -x 
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += $(OPTIONS)

C_FLAGS += -c
C_FLAGS += $(OPTIONS)
C_FLAGS += -fsingle-precision-constant -Wdouble-promotion
C_FLAGS += -ffunction-sections -fdata-sections
C_FLAGS += -I$(INC_DIR)
C_FLAGS += -I$(CMSIS_DEV_DIR)
C_FLAGS += -I$(CMSIS_INC_DIR)

L_FLAGS += $(MCU)
L_FLAGS += -mthumb
L_FLAGS += -nostartfiles
L_FLAGS += -Xlinker
L_FLAGS += --gc-sections 
L_FLAGS += -T./$(LD_SCRIPT)

OBJ_COPY_FLAGS += -S
OBJ_COPY_FLAGS += -O 
OBJ_COPY_FLAGS += binary

C_OBJECT_FILES := $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))

ASM_OBJECT_FILES := $(patsubst $(SRC_DIR)%.s,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.s))

.PHONY: all
all: $(C_OBJECT_FILES) $(BIN_DIR)
	make clean
	$(COMPILER) $(C_FLAGS) $(SRC_DIR)$(TARGET).c -o $(BIN_DIR)$(TARGET).o
	make $(BIN_DIR)$(TARGET).bin

# compile the user provided application c source files
$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILER) $(C_FLAGS) $< -o $@

# compile the user provided application assmebly source files
$(BIN_DIR)%.o: $(SRC_DIR)%.s
	$(COMPILER) $(ASM_FLAGS) $< -o $@

$(BIN_DIR)$(TARGET).elf: $(C_OBJECT_FILES) $(ASM_OBJECT_FILES) $(BIN_DIR)$(TARGET).o
	$(COMPILER) $^ $(L_FLAGS) -o $@

$(BIN_DIR)$(TARGET).bin: $(BIN_DIR)$(TARGET).elf
	$(OBJECT_COPY) $(OBJ_COPY_FLAGS) $< $@
	$(OBJECT_DUMP) -D $(BIN_DIR)$(TARGET).elf > $(BIN_DIR)$(TARGET).list
	$(OBJECT_SIZE) $<

write: $(BIN_DIR)$(TARGET).bin
	st-flash erase
	st-flash --reset write $(BIN_DIR)$(TARGET).bin 0x08000000

# if ./bin/ does not exist, create the directory
$(BIN_DIR):
	mkdir $@

clean:
	rm -f $(BIN_DIR)*.o
	rm -f $(BIN_DIR)*.out
	rm -f $(BIN_DIR)*.elf
	rm -f $(BIN_DIR)*.bin
	rm -f $(BIN_DIR)*.list
