# Versione minima richiesta di CMake
cmake_minimum_required(VERSION 3.10)

# Nome del progetto
project(Esercizio2)

# Imposta la variabile per i file sorgenti
set(SOURCES main.cpp Models/Vettore.h)

# Aggiungi l'eseguibile
add_executable(Esercizio2 ${SOURCES})
