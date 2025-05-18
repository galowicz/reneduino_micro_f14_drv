# 1 Includes
# 2 Variables
# ROOT := /home/user/Documents/Projects/mcu/RL78_Drivers
ROOT := .
BUILD_DIR := $(ROOT)/Build
ARTIFACT_NAME := RL78_drivers

# rl78/g14
MCU := R5F10AGE

CFLAGS :=	-std=gnu2x -mcpu=s3 --target=rl78
CFLAGS += 	-Wunused -Wuninitialized -Wall -Wextra -Wmissing-declarations -Wconversion -Wpointer-arith -Wshadow -Waggregate-return
CFLAGS +=	-ffunction-sections -fdata-sections -fdiagnostics-parseable-fixits -fno-strict-aliasing -fstack-size-section
CFLAGS += 	-MMD -MP

SFLAGS := 	$(CFLAGS) -x assembler-with-cpp

LDFLAGS := $(CFLAGS)
LDFLAGS += -T $(ROOT)/Cfg/linker_script_$(MCU).ld
LDFLAGS += -Wl,-Map=$(BUILD_DIR)/$(ARTIFACT_NAME).map
# LDFLAGS += -Wl,--start-group -l$(BUILD_DIR)/$(ARTIFACT_NAME)  -Wl,--end-group
LDFLAGS += -nostartfiles
LDFLAGS += -Wl,-e_PowerON_Reset
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--cref
LDFLAGS += -Wl,--icf=none

# Compiler toolchain in RL78_PATH global variable
CC := $(RL78_LLVM_PATH)/bin/clang
ASM := $(RL78_LLVM_PATH)/bin/clang
OBJCOPY := $(RL78_LLVM_PATH)/bin/llvm-objcopy
SIZE := $(RL78_LLVM_PATH)/bin/llvm-size
READELF := $(RL78_LLVM_PATH)/bin/llvm-readelf
RFP_CLI := rfp-cli
RM := rm -rf
RMDIR := rmdir
LIBS :=

# 3 Include Dirs
cinclude_dirs :=
cinclude_dirs += $(ROOT)/Cfg/
cinclude_dirs += $(ROOT)/Src/
cinclude_dirs += $(ROOT)/Src/Lib/
cinclude_dirs += $(ROOT)/Src/Lib/Ring_Buffer/
cinclude_dirs += $(ROOT)/Src/Port/
cinclude_dirs += $(ROOT)/Src/Dio/
cinclude_dirs += $(ROOT)/Src/Lin/
cinclude_dirs += $(ROOT)/Src/Usart/

sinclude_dirs :=

# 4 Sources

csources :=
csources += $(ROOT)/Cfg/hwinit.c
csources += $(ROOT)/Cfg/opt_bytes_$(MCU).c
csources += $(ROOT)/Cfg/vects_$(MCU).c
csources += $(ROOT)/Cfg/inthandler_$(MCU).c
csources += $(ROOT)/Src/Lib/Ring_Buffer/RingBuffer_uint8.c
csources += $(ROOT)/Src/main.c
# csources += $(ROOT)/Src/shiftout.c
csources += $(ROOT)/Src/Port/Port_Cfg.c
csources += $(ROOT)/Src/Port/Port.c
csources += $(ROOT)/Src/Dio/Dio.c
csources += $(ROOT)/Src/Dio/Dio_Cfg.c
csources += $(ROOT)/Src/Lin/Lin.c
csources += $(ROOT)/Src/Lin/Lin_Rlin3.c
csources += $(ROOT)/Src/Usart/Usart_Cfg.c
csources += $(ROOT)/Src/Usart/Usart.c

ssources :=
ssources += $(ROOT)/Cfg/start.s
ssources += $(ROOT)/Src/shiftout.s

objects := $(csources:$(ROOT)%.c=$(BUILD_DIR)%.c.o) $(ssources:$(ROOT)%.s=$(BUILD_DIR)%.s.o)

# includes := $(cinclude_dirs) $(sinclude_dirs)
includes := $(subst $(ROOT),-I $(ROOT),$(cinclude_dirs))
output_dirs := $(subst $(ROOT),$(BUILD_DIR),$(cinclude_dirs))

# 5 Rules
all: $(BUILD_DIR)/Src release run

$(BUILD_DIR)/Src:
	$(VERB)mkdir -p $(output_dirs)

prepare-release:
	$(eval CFLAGS += -O2)

prepare-debug:
	$(eval CFLAGS += -Og -g -gdwarf-3)
	$(eval LDFLAGS += -g -gdwarf-3)

$(BUILD_DIR)/%.s.o: $(ROOT)/%.s
	@echo "Building: $@"
	$(ASM) $(SFLAGS) $(includes) -MF"$(@:%.o=%.d)" -MT"$@" -c -o $@ $<
	@echo ''

$(BUILD_DIR)/%.C.o: $(ROOT)/%.C
$(BUILD_DIR)/%.c.o: $(ROOT)/%.c
	@echo "Building file: $@"
	$(CC) $(CFLAGS) $(includes)  -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" $< -c -o $@
	@echo ''

$(BUILD_DIR)/$(ARTIFACT_NAME).elf: $(BUILD_DIR)/Src $(objects)
	@echo "Linking: $@"
	$(CC) $(LDFLAGS) $(includes) -o "$@" $(objects)
	@echo  'Build finished'
	@echo ''

$(BUILD_DIR)/$(ARTIFACT_NAME).bin: $(BUILD_DIR)/$(ARTIFACT_NAME).elf
$(BUILD_DIR)/$(ARTIFACT_NAME).hex: $(BUILD_DIR)/$(ARTIFACT_NAME).elf
	@echo  'Create Flash image'
	$(OBJCOPY) $(BUILD_DIR)/$(ARTIFACT_NAME).elf -O ihex $(BUILD_DIR)/$(ARTIFACT_NAME).hex
	$(OBJCOPY) $(BUILD_DIR)/$(ARTIFACT_NAME).elf -O binary $(BUILD_DIR)/$(ARTIFACT_NAME).bin
	@echo ''
	@echo ''

print_size:
	$(SIZE) --format=berkeley -x --totals $(BUILD_DIR)/$(ARTIFACT_NAME).elf

release: prepare-release $(BUILD_DIR)/$(ARTIFACT_NAME).elf print_size
	@echo  "Build done in mode: Release"
	@echo ''

debug: prepare-debug $(BUILD_DIR)/$(ARTIFACT_NAME).elf print_size
	@echo  "Build done in mode: Debug"
	@echo ''

run: $(BUILD_DIR)/$(ARTIFACT_NAME).hex
	@echo "Programming"
	$(RFP_CLI) -d rl78 -port /dev/ttyUSB0 -s 115200 -dtr -rts-inv -erase -program -verify $(BUILD_DIR)/$(ARTIFACT_NAME).hex
	@echo ''

clean:
	@echo  "Cleanning"
	$(RM) $(BUILD_DIR)/$(ARTIFACT_NAME).*
	$(RM) $(BUILD_DIR)/Src/
	$(RM) $(BUILD_DIR)/Cfg/
	$(RMDIR) $(BUILD_DIR)
	@echo ''

help:
	@echo "Usage:\n\t- all - build release and run\n\t- release - build in release mode\n\t- debug - build in debug mode\n\t- run - program mcu\n\t- clean - cleanup\n\t- help - print this message\n"

.PHONY: all prepare-release prepare-debug build link clean release debug run help

