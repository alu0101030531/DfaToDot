// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Autómatas Finitos Deterministas
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 30/10/2019
// Archivo alfabeto.h: Define un alfabeto que almacena en un set los símbolos del
//                      mismo, permite devolver los symbols, cambiar el alfabeto por otro
//                      y mostrar por pantalla los símbolos.
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    27/10/2019 - Creación del código

#ifndef ALFABETO_H
#define ALFABETO_H

#include <set>
#include <iostream>
#include <string>

// Ejemplo de uso:
//  std::set<Symbol> symbols = {'a','b','c'}
//  Alfabeto alphabet(symbols);
//  alphabet.getSymbols();
class Alfabeto {
 public:
  Alfabeto() {};
  Alfabeto(std::set<char> symbols);
  friend std::ostream& operator<<(std::ostream& os, const Alfabeto& obj);
  void setAlphabet(std::set<char>& symbols) {symbols_ == symbols;};
  std::set<char> getSymbols() const {return symbols_;};
 private:
  std::set<char> symbols_;        // Almacena los símbolos del alfabeto
};
#endif //ALFABETO_H
