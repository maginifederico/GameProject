cmake_minimum_required(VERSION 3.7)
project(Game)

set(CMAKE_CXX_STANDARD 11)

#INSERIRE ALL'ISTRUZIONE SEGUENTE, DOPO "SOURCE_FILES", TUTTI GLI HEADER E SOURCE FILE DI CUI SI VUOLE ESEGUIRE LO UNIT TESTING. I FILE INSERITI NELLA VARIABILE SOURCE_FILE NON DEVONO ESSERE REINSERITI NELL'ISTRUZIONE A RIGO 8 DI ADD EXECUTABLE
set(SOURCE_FILES GameCharacter.h)
add_executable(Game ${SOURCE_FILES} main.cpp Layer.h Obstacle.h Item.h GameHero.h Map.h GameHero.cpp Obstacle.cpp Item.cpp GameHero.cpp Tile.cpp Tile.h Layer.cpp GameCharacter.cpp Map.cpp Collision.cpp Collision.h)

#PER GOOGLE TEST SCOMMENTARE TUTTE LE ISTRUZIONI SEGUENTI fino a riga 20. PER UNIT TESTING VEDI LIBRO DA PAGINA 248


#add_subdirectory(test)

#LA RIGA 7 SOSTITUISCE LA RIGA 16, AGGIUNGERE NELLA RIGA 7 I FILE DA SOTTOPORRE A TEST
#set(SOURCE_FILES header e source tutti per googletest)

#add_executable(patagame_unit_testing main.cpp)
#add_library(core ${SOURCE_FILES})
#target_link_libraries(patagame_unit_testing core)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED system graphics window network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})
endif ()