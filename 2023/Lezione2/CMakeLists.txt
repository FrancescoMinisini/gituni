# Versione minima richiesta di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(Lezione2)

# Imposta la variabile per i file sorgenti
set(SOURCES main.cpp Models/Vettore.cpp)

# Aggiungi l'eseguibile
add_executable(Lezione2 ${SOURCES})
