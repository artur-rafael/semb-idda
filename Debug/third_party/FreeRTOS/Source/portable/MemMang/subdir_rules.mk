################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
third_party/FreeRTOS/Source/portable/MemMang/%.obj: ../third_party/FreeRTOS/Source/portable/MemMang/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me -O4 --include_path="C:/ti/ccs1011/ccs/tools/compiler/ti-cgt-arm_20.2.3.LTS/include" --include_path="C:/Users/artur/Desktop/SEmb/Firmware/ProjectRTOS-IDDA" --include_path="C:/Users/artur/Desktop/SEmb/Firmware/ProjectRTOS-IDDA/inc" --include_path="C:/Users/artur/Desktop/SEmb/Firmware/SEmbLib/inc" --include_path="C:/Users/artur/Desktop/SEmb/Firmware/SEmbLibRTOS/inc" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/examples/boards/ek-tm4c123gxl" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/third_party" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/third_party/FreeRTOS/Source/include" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/third_party/FreeRTOS" --include_path="C:/ti/TivaWare_C_Series-2.1.4.178/third_party/FreeRTOS/Source/portable/CCS/ARM_CM4F" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --c99 --gcc --printf_support=minimal --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="third_party/FreeRTOS/Source/portable/MemMang/$(basename $(<F)).d_raw" --obj_directory="third_party/FreeRTOS/Source/portable/MemMang" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


