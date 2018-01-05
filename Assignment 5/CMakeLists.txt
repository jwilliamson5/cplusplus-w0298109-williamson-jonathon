cmake_minimum_required(VERSION 3.9)
project(Assignment_5)

set(CMAKE_CXX_STANDARD 11)
set(BUILD_SHARED_LIBS OFF)


add_executable(Assignment_5 main.cpp City.cpp City.h GameSpecs.h Human.cpp Human.h Organism.cpp Organism.h Zombie.cpp Zombie.h)