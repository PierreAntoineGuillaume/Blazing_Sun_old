cmake_minimum_required(VERSION 3.2)
project(Blazing_Sun)
#message(WARNING ${CMAKE_MODULE_PATH})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 ")#-mwindows")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SOURCE_FILES src/main.cpp)

set(EXECUTABLE_NAME Blazing_Sun)

add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES}

src/Generic/ResourceManager/ResourceManager.cpp
src/Generic/ResourceManager/ResourceManager.h
src/Generic/GameObject/GameObject.cpp
src/Generic/GameObject/GameObject.h
src/Generic/ResourceManager/Animator.cpp
src/Generic/ResourceManager/Animator.h
src/Generic/Engine/Interfaces/Movable.h
src/Generic/Engine/Interfaces/Collidable.h
src/Generic/Engine/Collider.cpp
src/Generic/Engine/Collider.h
src/Generic/Engine/Movement.cpp
src/Generic/Engine/Movement.h
src/Generic/Utility/Typedef.hpp
src/Generic/Utility/TypeComparisonStruct.hpp
src/Generic/ResourceManager/Information/FilePath.cpp
src/Generic/ResourceManager/Information/FilePath.h src/Generic/ResourceManager/Information/InformationHolder.cpp src/Generic/ResourceManager/Information/InformationHolder.h src/Generic/Utility/GameException.cpp src/Generic/Utility/GameException.h)


include(configSFMLMakefileHelper.txt)


