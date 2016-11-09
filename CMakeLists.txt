add_custom_target(myinstall COMMAND ${CMAKE_MAKE_PROGRAM} install)

cmake_minimum_required(VERSION 3.6)
project(RobotShop)

INCLUDE_DIRECTORIES(/usr/local/include)
LINK_DIRECTORIES(/usr/local/lib)

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -framework Cocoa")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp arm.h arm.cpp battery.cpp battery.h controller.cpp controller.h customer.cpp customer.h head.cpp head.h locomotor.cpp locomotor.h model.cpp model.h order.cpp order.h part.cpp part.h sa.cpp sa.h shop.cpp shop.h torso.cpp torso.h  )
add_executable(RobotShop ${SOURCE_FILES})
TARGET_LINK_LIBRARIES(RobotShop fltk)