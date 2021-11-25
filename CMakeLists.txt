cmake_minimum_required(VERSION 3.18)

project(sudoku)

if (MSVC)
    # warning level 4 and all warnings as errors
    add_compile_options(/W4 /WX)
else()
    # lots of warnings and all warnings as errors
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

enable_testing()

add_library(smorse smorse.cpp)

add_library(test_smorse test_smorse.cpp)
target_link_libraries(test_smorse smorse)

add_executable(test_smorse_main test_smorse_main.cpp)

target_link_libraries(test_smorse_main test_smorse)

function(do_test target arg result)
    add_test(NAME ${target}_${arg}_${result} COMMAND ${target}_main ${arg} ${result})
endfunction(do_test)

do_test(test_smorse sos ...---...)
do_test(test_smorse daily -...-...-..-.--)
do_test(test_smorse programmer .--..-.-----..-..-----..-.)
do_test(test_smorse bits -.....-...)
do_test(test_smorse three -.....-...)
