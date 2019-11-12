cmake_minimum_required(VERSION 3.15)
project(AbstractVm)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(AbstractVm
        EOperandType.hpp
        Errors.hpp
        Factory.cpp
        Factory.hpp
        IOperand.hpp
        main.cpp
        TOperand.cpp
        TOperand.hpp
        Vm.cpp
        Vm.hpp AbstractVm.hpp parser.cpp)
