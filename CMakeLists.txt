cmake_minimum_required(VERSION 3.14)
project(hm)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.17.0
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_GetProperties(googletest)
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BINARY_DIR})
endif()

include_directories(${gtest_SOURCE_DIR}/include)
include_directories("include/")

enable_testing()

file(GLOB_RECURSE TESTS_SRCS_CXX "tests/*.cc")
file(GLOB_RECURSE SRCS_CXX "src/*.cc")

set(TEST_BINARY ${PROJECT_NAME}_suit)

add_library(${PROJECT_NAME}_shared SHARED ${SRCS_CXX})
set_target_properties(${PROJECT_NAME}_shared PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}
  RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
  LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

add_library(${PROJECT_NAME}_static STATIC ${SRCS_CXX})
set_target_properties(${PROJECT_NAME}_static PROPERTIES
  OUTPUT_NAME ${PROJECT_NAME}
  ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
)

add_executable(${TEST_BINARY} ${TESTS_SRCS_CXX})

target_link_libraries(${TEST_BINARY}
  GTest::gtest
  GTest::gtest_main
  ${PROJECT_NAME}_shared
)

if(UNIX)
  target_link_libraries(${TEST_BINARY} pthread)
endif()

add_test(NAME  ${PROJECT_NAME} COMMAND ${TEST_BINARY})
