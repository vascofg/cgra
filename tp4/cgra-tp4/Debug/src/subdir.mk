################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/LightingScene.cpp \
../src/Plane.cpp \
../src/main.cpp \
../src/myCylinder.cpp \
../src/myLamp.cpp \
../src/myTable.cpp \
../src/myUnitCube.cpp \
../src/textures.cpp 

OBJS += \
./src/LightingScene.o \
./src/Plane.o \
./src/main.o \
./src/myCylinder.o \
./src/myLamp.o \
./src/myTable.o \
./src/myUnitCube.o \
./src/textures.o 

CPP_DEPS += \
./src/LightingScene.d \
./src/Plane.d \
./src/main.d \
./src/myCylinder.d \
./src/myLamp.d \
./src/myTable.d \
./src/myUnitCube.d \
./src/textures.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
<<<<<<< HEAD
	g++ -I"/home/andre/Dropbox/mieic/cgra/cgra-practical-classes/tp4/cgra-tp4/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
=======
	g++ -I"/home/vascofg/git/cgra-practical-classes/tp4/cgra-tp4/include" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o"$@" "$<"
>>>>>>> 3eeaf93f64eac8eb22090ed921cae6ef859ad632
	@echo 'Finished building: $<'
	@echo ' '


