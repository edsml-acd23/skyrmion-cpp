cmake_minimum_required(VERSION 3.27)
project(skyrmion_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(mcsim)

add_executable(skyrmion_cpp
        mcsim/driver.cpp
        mcsim/driver.h
        mcsim/spins.cpp
        mcsim/spins.h
        mcsim/system.cpp
        mcsim/system.h
        main.cpp)
