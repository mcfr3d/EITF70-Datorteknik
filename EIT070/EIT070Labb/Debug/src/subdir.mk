################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
LD_SRCS += \
../src/lscript.ld 

S_SRCS += \
../src/microBlaze.s 

C_SRCS += \
../src/displays.c \
../src/interrupt_controller.c \
../src/main.c \
../src/timer.c 

S_UPPER_SRCS += \
../src/AssemblyImplementations.S 

OBJS += \
./src/AssemblyImplementations.o \
./src/displays.o \
./src/interrupt_controller.o \
./src/main.o \
./src/microBlaze.o \
./src/timer.o 

S_UPPER_DEPS += \
./src/AssemblyImplementations.d 

C_DEPS += \
./src/displays.d \
./src/interrupt_controller.d \
./src/main.d \
./src/timer.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I../../EIT070Labb_bsp/microblaze_0/include -mlittle-endian -mcpu=v9.4 -mxl-soft-mul -Wl,--no-relax -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc compiler'
	mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"$@" -I../../EIT070Labb_bsp/microblaze_0/include -mlittle-endian -mcpu=v9.4 -mxl-soft-mul -Wl,--no-relax -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/%.o: ../src/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MicroBlaze gcc assembler'
	mb-as -mlittle-endian -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


