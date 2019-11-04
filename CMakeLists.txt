cmake_minimum_required(VERSION 3.14)
project(AbstractVmCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AbstractVmCpp
        main.cpp
        Vm.cpp
        Vm.hpp
        Factory.cpp
        Factory.hpp
        TOperand.cpp
        TOperand.hpp
        EOperandType.hpp
        IOperand.hpp
)
