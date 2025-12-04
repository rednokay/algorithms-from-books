cmake_minimum_required(VERSION 3.21)
project(GridironLab LANGUAGES CXX)

set(CMAKE_DISABLE_FIND_PACKAGE_Catch2 ON)
add_subdirectory(tests/catch2 EXCLUDE_FROM_ALL)

# -- C** standard --
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# -- Warnings & errors --
add_compile_options(-Wall -Wextra -Wpedantic -Werror)

# -- Executable --
add_executable(sort
    main.cc
)

target_include_directories(sort PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# find_package(Catch2 3 REQUIRED)
add_executable(run_tests
    tests/test.cc
    )

target_link_libraries(run_tests PRIVATE Catch2::Catch2WithMain)
target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
