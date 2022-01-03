# CMakeList.txt: 顶层 CMake 项目文件，在此处执行全局配置
# 并包含子项目。
#
cmake_minimum_required (VERSION 3.8)

project ("modules")

# 包含子项目。
add_executable(KMP
 src/KMP/main.cpp
 src/KMP/KMP_solution.h
 src/KMP/RandomInput.h
)

add_executable(BackTrack
 src/BackTrack/main.cpp
 src/BackTrack/BackTrack_solution.h
 src/BackTrack/RandomInput.h
)

add_executable(Tree
 src/Tree/main.cpp
 src/Tree/Tree.h
src/Tree/Tree.cpp
)