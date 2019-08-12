add_subdirectory(./lib/googletest-master/googletest)
set(gtest_SOURCE_DIR, ./lib/googletest-master/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


#LE PRIME DUE RIGHE SONO QUASI SICURAMENTE DA SOSTITUIRE CON LE SEGUENTI DUE:
#add_subdirectory(./lib/googletest-master/googletest)
#set(gtest_SOURCE_DIR, ./lib/googletest-master/googletest/)


#set(TEST_SOURCE_FILES runAllTests.cpp + tutti i test e fixture, ESEMPIO -> GameCharacterTest.cpp GameCharacterFixture.cpp)
#add_executable(runAllTests ${TEST_SOURCE_FILES})
#target_link_libraries(runAllTests gtest gtest_main core)