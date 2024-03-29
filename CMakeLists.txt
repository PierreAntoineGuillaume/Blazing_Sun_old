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
        src/Generic/Utility/exception/GameException.cpp
        src/Generic/Utility/exception/GameException.h
        src/Generic/Engine/Interfaces/Collidable.h
        src/Generic/Engine/Collider.cpp
        src/Generic/Engine/Collider.h
        src/Generic/Utility/point.hpp
        src/Generic/Utility/Holder.hpp
        src/Specific/MACROS.h
        src/Generic/Utility/polygon.hpp
        src/Generic/ResourceManager/Resource.cpp
        src/Generic/ResourceManager/Resource.h
        src/Generic/ResourceManager/CompositeResource.cpp
        src/Generic/ResourceManager/CompositeResource.h
        src/Generic/ResourceManager/ResourceDescriptor.cpp
        src/Generic/ResourceManager/ResourceDescriptor.h
        src/Generic/ResourceManager/Animation.cpp
        src/Generic/ResourceManager/Animation.h
        src/Generic/GameObject/Player.h
        src/Generic/GameObject/Player.cpp
        src/Generic/Engine/GameObjectFactory.h
        src/Generic/Engine/GameObjectFactory.cpp
        src/Generic/GameObject/Character.h
        src/Generic/GameObject/Decoration.h
        src/Generic/GameObject/Entity.h
        src/Generic/GameObject/Foreground.h
        src/Generic/GameObject/Character.cpp
        src/Generic/GameObject/Decoration.cpp
        src/Generic/GameObject/Entity.cpp
        src/Generic/GameObject/Foreground.cpp
        src/Generic/Network/Client.cpp
        src/Generic/Network/Client.h
        src/Generic/Network/Server.cpp
        src/Generic/Network/Server.h src/Generic/Utility/exception/invalid_gameobject.cpp src/Generic/Utility/exception/invalid_gameobject.h)

set(EXECUTABLE_NAME ${PROJECT_NAME})


add_executable(${EXECUTABLE_NAME} ${SOURCE_FILES})
SET_TARGET_PROPERTIES(Blazing_Sun PROPERTIES LINKER_LANGUAGE CXX)

set(SFML_ROOT C:/lib/SFML-2.3.2)
find_package(SFML 2 REQUIRED audio graphics network window system)

if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif(SFML_FOUND)
MESSAGE (WARNING "${Blazing_Sun_BINARY_DIR}")