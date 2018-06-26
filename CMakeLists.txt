cmake_minimum_required(VERSION 3.2)

project(helloworld VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

#find_package(Boost COMPONENTS unit_test_framework REQUIRED)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

configure_file(version.h.in version.h)

add_executable(helloworld_cli main.cpp)

add_library(helloworld lib.cpp)

#add_executable(test_main_cli test_main.cpp)
# Link runTests with what we want to test and the GTest and pthread library
add_executable(runTests tests.cpp)

#set_target_properties(helloworld_cli test_main_cli PROPERTIES
set_target_properties(helloworld_cli runTests PROPERTIES
  CXX_STANDARD 14
  CXX_STANDARD_REQUIRED ON
  COMPILE_OPTIONS -Wpedantic -Wall -Wextra
)

#set_target_properties(test_main_cli PROPERTIES
#  COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#  INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIR}
#)

target_link_libraries(helloworld_cli helloworld)

#target_link_libraries(test_main_cli
#  ${Boost_LIBRARIES}
#  helloworld
#)
target_link_libraries(runTests
  ${GTEST_LIBRARIES}
  helloworld)

install(TARGETS helloworld_cli RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT george.garnov@gmail.com)

include (CPack)

enable_testing()

add_test(test_version_valid runTests)
