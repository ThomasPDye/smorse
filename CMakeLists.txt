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

add_library(bonus_smorse bonus_smorse.cpp)
target_link_libraries(bonus_smorse smorse)

add_library(test_bonus_1_a_smorse test_bonus_1_a_smorse.cpp)
target_link_libraries(test_bonus_1_a_smorse bonus_smorse)

add_executable(test_bonus_1_a_smorse_main test_bonus_1_a_smorse_main.cpp)
target_link_libraries(test_bonus_1_a_smorse_main test_bonus_1_a_smorse)

add_library(answer_bonus_1_b_smorse answer_bonus_1_b_smorse.cpp)
target_link_libraries(answer_bonus_1_b_smorse bonus_smorse)

add_executable(answer_bonus_1_b_smorse_main answer_bonus_1_b_smorse_main.cpp)
target_link_libraries(answer_bonus_1_b_smorse_main answer_bonus_1_b_smorse)

add_library(test_bonus_2_a_smorse test_bonus_2_a_smorse.cpp)
target_link_libraries(test_bonus_2_a_smorse bonus_smorse)

add_executable(test_bonus_2_a_smorse_main test_bonus_2_a_smorse_main.cpp)
target_link_libraries(test_bonus_2_a_smorse_main test_bonus_2_a_smorse)

function(do_test target arg result)
    add_test(NAME ${target}_${arg}_is_${result} COMMAND ${target}_main ${arg} ${result})
endfunction(do_test)

do_test(test_smorse sos ...---...)
do_test(test_smorse daily -...-...-..-.--)
do_test(test_smorse programmer .--..-.-----..-..-----..-.)
do_test(test_smorse bits -.....-...)
do_test(test_smorse three -.....-...)

add_test(NAME test_bonus_1_a COMMAND test_bonus_1_a_smorse_main ${CMAKE_SOURCE_DIR}/enable1.txt -...-....-.--. needing nervate niding tiling)
set_tests_properties(test_bonus_1_a PROPERTIES REQUIRED_FILES ${CMAKE_SOURCE_DIR}/enable1.txt)

add_test(NAME answer_bonus_1_b COMMAND answer_bonus_1_b_smorse_main ${CMAKE_SOURCE_DIR}/enable1.txt 13)
set_tests_properties(answer_bonus_1_b PROPERTIES REQUIRED_FILES ${CMAKE_SOURCE_DIR}/enable1.txt PASS_REGULAR_EXPRESSION "-....--.... 13  babe bans bates bath begs deans death digs dimes duns neeps nips tsadi")

add_test(NAME test_bonus_2_a COMMAND test_bonus_2_a_smorse_main autotomous - 14)
