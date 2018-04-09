################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
portable/heap_2.obj: ../portable/heap_2.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="portable/heap_2.pp" --obj_directory="portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

portable/port.obj: ../portable/port.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="portable/port.pp" --obj_directory="portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

portable/portasm.obj: ../portable/portasm.asm $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="portable/portasm.pp" --obj_directory="portable" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


