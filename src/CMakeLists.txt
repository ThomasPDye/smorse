add_library(smorse smorse.cpp)

add_library(bonus_smorse bonus_smorse.cpp)
target_link_libraries(bonus_smorse smorse)
