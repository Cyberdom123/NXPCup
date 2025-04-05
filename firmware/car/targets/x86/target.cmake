set(NAME x86)

include(${CMAKE_CURRENT_LIST_DIR}/requirements.cmake)
FetchContent_MakeAvailable(googletest)
enable_testing()

set(ALGORITHMS_DIR ${CMAKE_CURRENT_SOURCE_DIR}/targets/MKV/algorithms)
set(APPLICATION_DIR ${CMAKE_CURRENT_SOURCE_DIR}/targets/MKV/application)

add_executable(
  x86
  # test sources
  ${CMAKE_CURRENT_LIST_DIR}/algorithm_test.cpp
  ${CMAKE_CURRENT_LIST_DIR}/uart_frame_test.cpp
  # project sources
  ${ALGORITHMS_DIR}/camera.cpp
  ${APPLICATION_DIR}/uart_frame.cpp
)

target_include_directories(
  x86
  PRIVATE
  ${ALGORITHMS_DIR}/../
  ${APPLICATION_DIR}/../
)

target_link_libraries(
  x86
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(x86)