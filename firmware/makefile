
DEFAULT_TARGET = main
TARGET = $(DEFAULT_TARGET)

LD_SCRIPT = $(THIRD_PARTY_DIR)stm32F334K6TX_mem_map.ld

CPU = -mcpu=cortex-m4
MCU = $(CPU) -mthumb

TOOLCHAIN   = arm-none-eabi
COMPILER    = $(TOOLCHAIN)-gcc
OBJECT_COPY = $(TOOLCHAIN)-objcopy
OBJECT_DUMP = $(TOOLCHAIN)-objdump
OBJECT_SIZE = $(TOOLCHAIN)-size

BSP_DIR         = ./BSP/
LIB_DIR         = ./lib/
SRC_DIR         = ./src/
THIRD_PARTY_DIR = ./third_party/
CMSIS_DEV_DIR   = $(THIRD_PARTY_DIR)CMSIS/Device/
CMSIS_INC_DIR   = $(THIRD_PARTY_DIR)CMSIS/Include/
BIN_DIR         = ./bin/

OPTIONS += $(MCU)
OPTIONS += -Os
OPTIONS += -Wall
OPTIONS += -fdata-sections
OPTIONS += -ffunction-sections

ASM_FLAGS += -c
ASM_FLAGS += -x 
ASM_FLAGS += assembler-with-cpp
ASM_FLAGS += $(OPTIONS)

C_FLAGS += -c
C_FLAGS += $(OPTIONS)
C_FLAGS += -I$(BSP_DIR)
C_FLAGS += -I$(LIB_DIR)
C_FLAGS += -I$(SRC_DIR)
C_FLAGS += -I$(CMSIS_DEV_DIR)
C_FLAGS += -I$(CMSIS_INC_DIR)

L_FLAGS += $(MCU)
L_FLAGS += -specs=nano.specs
L_FLAGS += -T./$(LD_SCRIPT)
L_FLAGS += -lc -lm -lnosys
L_FLAGS += -nostartfiles
L_FLAGS += -Wl,--gc-sections
L_FLAGS += -Wl,--print-memory-usage

OBJ_COPY_FLAGS += -S
OBJ_COPY_FLAGS += -O 
OBJ_COPY_FLAGS += binary

C_OBJECT_FILES  = $(patsubst $(SRC_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(SRC_DIR)*.c))
C_OBJECT_FILES += $(patsubst $(BSP_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(BSP_DIR)*.c))
C_OBJECT_FILES += $(patsubst $(LIB_DIR)%.c,$(BIN_DIR)%.o,$(wildcard $(LIB_DIR)*.c))

ASM_OBJECT_FILES := $(patsubst $(THIRD_PARTY_DIR)%.s,$(BIN_DIR)%.o,$(wildcard $(THIRD_PARTY_DIR)*.s))

.PHONY: all
all: $(C_OBJECT_FILES) $(BIN_DIR)
	$(COMPILER) $(C_FLAGS) $(SRC_DIR)$(TARGET).c -o $(BIN_DIR)$(TARGET).o
	make $(BIN_DIR)$(TARGET).bin

$(C_OBJECT_FILES): | $(BIN_DIR)

# compile the user provided application c source files
$(BIN_DIR)%.o: $(BSP_DIR)%.c
	$(COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)%.o: $(LIB_DIR)%.c
	$(COMPILER) $(C_FLAGS) $< -o $@

$(BIN_DIR)%.o: $(SRC_DIR)%.c
	$(COMPILER) $(C_FLAGS) $< -o $@

# compile the user provided application assmebly source files
$(BIN_DIR)%.o: $(THIRD_PARTY_DIR)%.s
	$(COMPILER) $(ASM_FLAGS) $< -o $@

$(BIN_DIR)$(TARGET).elf: $(C_OBJECT_FILES) $(ASM_OBJECT_FILES) $(BIN_DIR)$(TARGET).o
	$(COMPILER) $^ $(L_FLAGS) -o $@

$(BIN_DIR)$(TARGET).bin: $(BIN_DIR)$(TARGET).elf
	$(OBJECT_COPY) $(OBJ_COPY_FLAGS) $< $@
	$(OBJECT_DUMP) -D $(BIN_DIR)$(TARGET).elf > $(BIN_DIR)$(TARGET).list

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
