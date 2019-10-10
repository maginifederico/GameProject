cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(./lib/googletest-master)
set(gtest_SOURCE_DIR, ./lib/googletest-master)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

#set(TEST_SOURCE_FILES runAllTests.cpp + tutti i test e fixture, ESEMPIO -> GameCharacterTest.cpp GameCharacterFixture.cpp)
set(TEST_SOURCE_FILES runAllTests.cpp GameHeroTest.cpp WeaponTest.cpp EnemyTest.cpp)

add_executable(runAllTests ${TEST_SOURCE_FILES})
target_link_libraries(runAllTests gtest gtest_main core sfml-graphics sfml-window sfml-system sfml-audio)