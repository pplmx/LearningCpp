cmake_minimum_required(VERSION 3.19)
project(LearningCpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(TheFirstSln)

add_executable(LearningCpp
        TheFirstSln/base_graph.h
        TheFirstSln/digraph.cpp
        TheFirstSln/graph.cpp
        TheFirstSln/graph.h
        TheFirstSln/LinearThresholdModel.cpp
        TheFirstSln/LinearThresholdModel.h
        TheFirstSln/ThreadPool.h)
