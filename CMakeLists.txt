cmake_minimum_required(VERSION 2.8.4)
project(VacationCalculationCPP)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Currency.h Currency.cpp Expense.h Expense.cpp Person.h Person.cpp WhoPay.h WhoPay.cpp Event.h Event.cpp)

add_executable(VacationCalculationCPP ${SOURCE_FILES})