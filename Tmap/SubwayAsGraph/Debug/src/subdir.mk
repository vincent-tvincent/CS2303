################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/AdjMat.cpp \
../src/LinkedList.cpp \
../src/Production.cpp \
../src/Room.cpp \
../src/SubwayAsGraph.cpp \
../src/Terminal.cpp \
../src/Tests.cpp \
../src/demoCPP.cpp 

CPP_DEPS += \
./src/AdjMat.d \
./src/LinkedList.d \
./src/Production.d \
./src/Room.d \
./src/SubwayAsGraph.d \
./src/Terminal.d \
./src/Tests.d \
./src/demoCPP.d 

OBJS += \
./src/AdjMat.o \
./src/LinkedList.o \
./src/Production.o \
./src/Room.o \
./src/SubwayAsGraph.o \
./src/Terminal.o \
./src/Tests.o \
./src/demoCPP.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/AdjMat.d ./src/AdjMat.o ./src/LinkedList.d ./src/LinkedList.o ./src/Production.d ./src/Production.o ./src/Room.d ./src/Room.o ./src/SubwayAsGraph.d ./src/SubwayAsGraph.o ./src/Terminal.d ./src/Terminal.o ./src/Tests.d ./src/Tests.o ./src/demoCPP.d ./src/demoCPP.o

.PHONY: clean-src

