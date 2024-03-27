cmake_minimum_required(VERSION 3.22.1)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(CellScript)

if(MSVC)
    add_compile_options(/W4 -g)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -g)
endif()

set(CMAKE_C_COMPILER gcc)
set(CMAKE_CPP_COMPILER g++)

add_custom_command(
  OUTPUT foo.hh
  COMMAND /tmp/bin/create_foo_h main.cpp
  DEPENDS ${SOURCE_FILES} /tmp/bin/create_foo_hh main.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)

set(PROJECT_SRCS "lex.yy.cc" "parser.tab.cc" "datatypes.cc" "interpreter.cc" "program.cc")

add_executable(${PROJECT_NAME} ${PROJECT_SRCS})

target_link_libraries(${PROJECT_NAME} gmp gmpxx mpfr)

