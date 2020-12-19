################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS

GEN_OPTS__FLAG := 
GEN_CMDS__FLAG := 

ORDERED_OBJS += \
"./main.obj" \
"./src/distanceRTOS.obj" \
"./src/idda.obj" \
"./src/symbols.obj" \
"./startup/tm4c123gh6pm_startup_ccs.obj" \
"./third_party/FreeRTOS/Source/list.obj" \
"./third_party/FreeRTOS/Source/queue.obj" \
"./third_party/FreeRTOS/Source/tasks.obj" \
"./third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/port.obj" \
"./third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/portasm.obj" \
"./third_party/FreeRTOS/Source/portable/MemMang/heap_4.obj" \
"./utils/uartstdio.obj" \
"./utils/ustdlib.obj" \
"../startup/tm4c123gh6pm.cmd" \
$(GEN_CMDS__FLAG) \
-llibc.a \
-l"C:/Users/artur/Desktop/SEmb/Firmware/SEmbLib/Debug/SEmbLib.lib" \
-l"C:/Users/artur/Desktop/SEmb/Firmware/SEmbLibRTOS/Debug/SEmbLibRTOS.lib" \
-l"C:/ti/TivaWare_C_Series-2.1.4.178/driverlib/ccs/Debug/driverlib.lib" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include src/subdir_vars.mk
-include startup/subdir_vars.mk
-include third_party/FreeRTOS/Source/subdir_vars.mk
-include third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_vars.mk
-include third_party/FreeRTOS/Source/portable/MemMang/subdir_vars.mk
-include utils/subdir_vars.mk
-include subdir_rules.mk
-include src/subdir_rules.mk
-include startup/subdir_rules.mk
-include third_party/FreeRTOS/Source/subdir_rules.mk
-include third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F/subdir_rules.mk
-include third_party/FreeRTOS/Source/portable/MemMang/subdir_rules.mk
-include utils/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(INO_DEPS)),)
-include $(INO_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(SV7A_DEPS)),)
-include $(SV7A_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(PDE_DEPS)),)
-include $(PDE_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
ProjectRTOS-IDDA.out \

EXE_OUTPUTS__QUOTED += \
"ProjectRTOS-IDDA.out" \

BIN_OUTPUTS += \
ProjectRTOS-IDDA.hex \

BIN_OUTPUTS__QUOTED += \
"ProjectRTOS-IDDA.hex" \


# All Target
all: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@$(MAKE) --no-print-directory -Onone "ProjectRTOS-IDDA.out"

dependents:
	-cd C:/Users/artur/Desktop/SEmb/Firmware/SEmbLib/Debug && $(MAKE) clean all
	-cd C:/Users/artur/Desktop/SEmb/Firmware/SEmbLibRTOS/Debug && $(MAKE) clean all

# Tool invocations
ProjectRTOS-IDDA.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS) C:/Users/artur/Desktop/SEmb/Firmware/SEmbLib/Debug/SEmbLib.lib C:/Users/artur/Desktop/SEmb/Firmware/SEmbLibRTOS/Debug/SEmbLibRTOS.lib
	@echo 'Building target: "$@"'
	@echo 'Invoking: ARM Linker'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O4 --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi -z -m"ProjectRTOS-IDDA.map" --heap_size=512 --stack_size=512 -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/lib" -i"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/include" --reread_libs --diag_wrap=off --display_error_number --warn_sections --xml_link_info="ProjectRTOS-IDDA_linkInfo.xml" --rom_model -o "ProjectRTOS-IDDA.out" $(ORDERED_OBJS)
	@echo 'Finished building target: "$@"'
	@echo ' '

ProjectRTOS-IDDA.hex: $(EXE_OUTPUTS)
	@echo 'Building files: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo 'Invoking: ARM Hex Utility'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/bin/armhex"  -o "ProjectRTOS-IDDA.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $(strip $(EXE_OUTPUTS__QUOTED))'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(BIN_OUTPUTS__QUOTED)$(EXE_OUTPUTS__QUOTED)
	-$(RM) "main.obj" "src\distanceRTOS.obj" "src\idda.obj" "src\symbols.obj" "startup\tm4c123gh6pm_startup_ccs.obj" "third_party\FreeRTOS\Source\list.obj" "third_party\FreeRTOS\Source\queue.obj" "third_party\FreeRTOS\Source\tasks.obj" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\port.obj" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.obj" "third_party\FreeRTOS\Source\portable\MemMang\heap_4.obj" "utils\uartstdio.obj" "utils\ustdlib.obj" 
	-$(RM) "main.d" "src\distanceRTOS.d" "src\idda.d" "src\symbols.d" "startup\tm4c123gh6pm_startup_ccs.d" "third_party\FreeRTOS\Source\list.d" "third_party\FreeRTOS\Source\queue.d" "third_party\FreeRTOS\Source\tasks.d" "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\port.d" "third_party\FreeRTOS\Source\portable\MemMang\heap_4.d" "utils\uartstdio.d" "utils\ustdlib.d" 
	-$(RM) "third_party\FreeRTOS\Source\portable\CCS\ARM_CM4F\portasm.d" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:
C:/Users/artur/Desktop/SEmb/Firmware/SEmbLib/Debug/SEmbLib.lib:
C:/Users/artur/Desktop/SEmb/Firmware/SEmbLibRTOS/Debug/SEmbLibRTOS.lib:

-include ../makefile.targets

