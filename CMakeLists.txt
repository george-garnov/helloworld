cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

set_target_properties(helloworld_cli PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

target_link_libraries(helloworld_cli helloworld)

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

add_executable(runTests tests.cpp)
target_link_libraries(runTests
  ${GTEST_BOTH_LIBRARIES}
  helloworld
  pthread
)

set_target_properties(helloworld_cli runTests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

set_target_properties(runTests PROPERTIES
  INCLUDE_DIRECTORIES ${GTEST_INCLUDE_DIRS}
)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT george.garnov@gmail.com)

include (CPack)

add_test(test_version_valid runTests)

