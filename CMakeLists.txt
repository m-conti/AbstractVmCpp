cmake_minimum_required(VERSION 3.14)
project(AbstractVmCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AbstractVmCpp
        AbstractVm.hpp
        EOperandType.hpp
        Errors.hpp
        Factory.cpp
        Factory.hpp
        IOperand.hpp
        main.cpp
        parser.cpp
        TOperand.cpp
        TOperand.hpp
        Vm.cpp
        Vm.hpp)
