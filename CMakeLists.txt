cmake_minimum_required(VERSION 2.6)

project(adventofcode-2017-cpp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

file(GLOB children RELATIVE ${CMAKE_HOME_DIRECTORY} ${CMAKE_HOME_DIRECTORY}/*)
foreach(child ${children})
    if(IS_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${child})
        if (${child} MATCHES "^day[0-2][0-9]$")
            message(${child})
            add_subdirectory(${child})
        endif()
    endif()
endforeach()
