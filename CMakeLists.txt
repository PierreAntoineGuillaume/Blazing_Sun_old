cmake_minimum_required(VERSION 3.2)

set(PROJECT_NAME Blazing_Sun)

project(${PROJECT_NAME})

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake/Module")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -Wall --pedantic -Wno-comment -Werror")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")


set(SOURCE_FILES
        src/main.cpp
        src/Generic/Engine/Collider.cpp
        src/Generic/Engine/Collider.h
        src/Generic/ResourceManager/ResourceManager.cpp
        src/Generic/ResourceManager/ResourceManager.h
        src/Generic/GameObject/GameObject.cpp
        src/Generic/GameObject/GameObject.h
        src/Generic/ResourceManager/Animator.cpp
        src/Generic/ResourceManager/Animator.h
        src/Generic/Engine/Interfaces/Movable.h
        src/Generic/Engine/Interfaces/Collidable.h
        src/Generic/Engine/Movement.cpp
        src/Generic/Engine/Movement.h
        src/Generic/Utility/Typedef.hpp
        src/Generic/Utility/TypeComparisonStruct.hpp
        src/Generic/Utility/GameException.cpp
        src/Generic/Utility/GameException.h
        src/Generic/Engine/Interfaces/Collidable.h
        src/Generic/Engine/Collider.cpp
        src/Generic/Engine/Collider.h
        src/Generic/Utility/point.hpp
        src/Generic/Utility/Holder.hpp
        src/Specific/MACROS.h
        src/Generic/Utility/polygon.hpp
        src/Generic/ResourceManager/Ressource.cpp
        src/Generic/ResourceManager/Ressource.h
        src/Generic/ResourceManager/CompositeRessource.cpp
        src/Generic/ResourceManager/CompositeRessource.h
        src/Generic/ResourceManager/RessourceDescriptor.cpp
        src/Generic/ResourceManager/RessourceDescriptor.h src/Generic/ResourceManager/Animation.cpp src/Generic/ResourceManager/Animation.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Blazing_Sun PROPERTIES LINKER_LANGUAGE CXX)

set(SFML_ROOT C:/lib/SFML-2.3.2)
find_package(SFML 2 REQUIRED audio graphics network window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif(SFML_FOUND)
