################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
ADC.obj: ../ADC.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="ADC.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

PWM.obj: ../PWM.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="PWM.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

WUSgui.obj: ../WUSgui.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="WUSgui.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

button.obj: ../button.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="button.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

list.obj: ../list.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="list.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

main.obj: ../main.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="main.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

messages.obj: ../messages.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="messages.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

mytimer.obj: ../mytimer.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="mytimer.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

queue.obj: ../queue.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="queue.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rit128x96x4.obj: ../rit128x96x4.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="rit128x96x4.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

startup_ccs.obj: ../startup_ccs.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="startup_ccs.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

tasks.obj: ../tasks.c $(GEN_OPTS) $(GEN_SRCS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv5/tools/compiler/arm_5.0.1/bin/armcl" -mv7M3 --code_state=16 --abi=eabi -me -g --include_path="C:/ti/ccsv5/tools/compiler/arm_5.0.1/include" --include_path="J:/Courses/ENCE361/StellarisWare" --include_path="J:/Courses/ENCE361/StellarisWare/utils" --include_path="J:/Courses/ENCE361/StellarisWare/boards/ek-lm3s1968" --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="tasks.pp" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


