################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Word/src/word.cpp 

OBJS += \
./Word/src/word.o 

CPP_DEPS += \
./Word/src/word.d 


# Each subdirectory must supply rules for building sources it contributes
Word/src/%.o: ../Word/src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++1y -I"/home/hsr/CPPTestat2/Word" -I"/home/hsr/CPPTestat2/cute" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


