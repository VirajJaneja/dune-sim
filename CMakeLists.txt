cmake_minimum_required(VERSION 3.31)
project(dune_sim)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FETCHCONTENT_DECLARE(SFML GIT_REPOSITORY https://github.com/SFML/SFML.git GIT_TAG 3.0.0)
FETCHCONTENT_MAKEAVAILABLE(SFML)


set(CMAKE_CXX_STANDARD 20)



add_executable(dune_sim main.cpp
        GameManager.cpp
        GameManager.h
        Sandworm.cpp
        Sandworm.h
        buttonPanel.cpp
        buttonPanel.h
)

target_link_libraries(dune_sim sfml-graphics)
