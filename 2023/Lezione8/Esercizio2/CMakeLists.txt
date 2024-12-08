# Versione minima richiesta di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(Esercizio2)

# Imposta lo standard C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specifica i percorsi di include e libreria di ROOT manualmente
include_directories("/snap/root-framework/936/usr/local/include")
link_directories("/snap/root-framework/936/usr/local/lib")

# Trova Armadillo
find_package(Armadillo REQUIRED)

# Imposta la variabile per i file sorgenti
set(SOURCES main.cpp Models/FunzioneBase.h)

# Aggiungi l'eseguibile
add_executable(Esercizio2 ${SOURCES})

# Collega le librerie ROOT e Armadillo all'eseguibile
target_link_libraries(Esercizio2 
    /snap/root-framework/936/usr/local/lib/libCore.so 
    /snap/root-framework/936/usr/local/lib/libHist.so 
    /snap/root-framework/936/usr/local/lib/libRIO.so 
    /snap/root-framework/936/usr/local/lib/libGraf.so 
    /snap/root-framework/936/usr/local/lib/libGpad.so
    ${ARMADILLO_LIBRARIES} # Aggiunge le librerie di Armadillo
)

# Include Armadillo nei percorsi di include
target_include_directories(Esercizio2 PRIVATE ${ARMADILLO_INCLUDE_DIRS})
