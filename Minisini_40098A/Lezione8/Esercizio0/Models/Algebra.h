#ifndef _ALGEBRA_H__
#define _ALGEBRA_H__

#include <vector>
#include <stdexcept>
#include <cmath>
#include <iostream>

class Vector {
private:
    std::vector<double> data;

public:
    // Costruttori
    Vector(size_t size) : data(size, 0.0) {}
    Vector(const std::vector<double>& vec) : data(vec) {}

    // Operatori
    Vector operator+(const Vector& other) const {
        if (data.size() != other.data.size()) 
            throw std::runtime_error("I vettori non sono conformi per la somma");
        
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    Vector operator-(const Vector& other) const {
        if (data.size() != other.data.size()) 
            throw std::runtime_error("I vettori non sono conformi per la sottrazione");
        
        Vector result(data.size());
        for (size_t i = 0; i < data.size(); ++i) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    double operator*(const Vector& other) const { // Prodotto scalare
        if (data.size() != other.data.size()) 
            throw std::runtime_error("I vettori non sono conformi per il prodotto scalare");
        
        double result = 0.0;
        for (size_t i = 0; i < data.size(); ++i) {
            result += data[i] * other.data[i];
        }
        return result;
    }

    Vector operator^(const Vector& other) const { // Prodotto vettoriale
        if (data.size() != 3 || other.data.size() != 3) 
            throw std::runtime_error("Il prodotto vettoriale è definito solo per vettori tridimensionali");
        
        Vector result(3);
        result.data[0] = data[1] * other.data[2] - data[2] * other.data[1];
        result.data[1] = data[2] * other.data[0] - data[0] * other.data[2];
        result.data[2] = data[0] * other.data[1] - data[1] * other.data[0];
        return result;
    }

    Vector& operator+=(const Vector& other) {
        if (data.size() != other.data.size()) 
            throw std::runtime_error("I vettori non sono conformi per l'operazione");
        
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] += other.data[i];
        }
        return *this;
    }

    Vector& operator-=(const Vector& other) {
        if (data.size() != other.data.size()) 
            throw std::runtime_error("I vettori non sono conformi per l'operazione");
        
        for (size_t i = 0; i < data.size(); ++i) {
            data[i] -= other.data[i];
        }
        return *this;
    }

    // Funzione per stampare il vettore (Debug)
    void print() const {
        for (const auto& val : data) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    // Getter e Setter
    size_t size() const { return data.size(); }
    double& operator[](size_t index) { return data[index]; }
    const double& operator[](size_t index) const { return data[index]; }
};

#endif 
