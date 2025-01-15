cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(MyRootProject)

# Versione del C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova ROOT
find_package(ROOT REQUIRED COMPONENTS Core RIO Hist Tree)

# Aggiungi i flag di compilazione specifici di ROOT
include(${ROOT_USE_FILE})

# Specifica i file sorgente e header
file(GLOB_RECURSE SOURCES 
    ${CMAKE_SOURCE_DIR}/Models/*.cpp
    ${CMAKE_SOURCE_DIR}/main.cpp
)

# Creazione dell'eseguibile
add_executable(MyRootExecutable ${SOURCES})

# Link con le librerie ROOT
target_link_libraries(MyRootExecutable ${ROOT_LIBRARIES})

# Aggiungi le directory di include
target_include_directories(MyRootExecutable PRIVATE ${CMAKE_SOURCE_DIR}/Models)
