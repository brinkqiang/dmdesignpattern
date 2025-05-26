cmake_minimum_required(VERSION 3.2)

PROJECT(dmdesignpattern)

LIST(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
INCLUDE(cmake/ModuleImport.cmake)
INCLUDE(cmake/ModuleCompileOptions.cmake)
ModuleSetCompileOptions()
ModuleSetWinCompilerFlags()

if (PROJECT_IS_TOP_LEVEL)
    ExeImport("examples" "")
endif(PROJECT_IS_TOP_LEVEL)
