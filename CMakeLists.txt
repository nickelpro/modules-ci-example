cmake_minimum_required(VERSION 3.31)

project(modules-ci-example)

add_library(mod)

target_sources(mod
  PRIVATE
    src/mod.cpp

  PUBLIC
    FILE_SET CXX_MODULES
    BASE_DIRS
      src
    FILES
      src/mod.cppm
)
target_compile_features(mod
  PRIVATE
    cxx_std_23
)
set_target_properties(mod
  PROPERTIES
    CXX_MODULE_STD 1
)

enable_testing()

add_executable(modtest)
target_sources(modtest
  PRIVATE
    test/modtest.cpp
)
target_link_libraries(modtest
  PRIVATE
    mod
)
target_compile_features(modtest
  PRIVATE
    cxx_std_23
)

add_test(modtest modtest)
