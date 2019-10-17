// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Calculadora de lenguajes regulares
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo transition.h: Permite crear transiciones 
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código

#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

const std::string OTHERSYMBOL = "other";    // Define una transición con cualquier simbolo

class Transition {
 public:
  Transition(std::string& symbol, int id);
  Transition(std::string& symbol, std::string& state_id);
  std::string getSymbol() const {return symbol_;}; 
  int getNextId() const {return state_id_;};
  bool hasAnyTransition() const {return any_;};
  friend std::ostream& operator<<(std::ostream& os, const Transition& obj);
  bool matchTransition(char symbol) const;
 private:
  std::string symbol_;    // Guarda el símbolo de la transición
  int state_id_;          // Estado al que transiciona
  bool any_;              // 1: en caso de transicionar con cualquier símbolo
};

inline bool operator<(const Transition& obj1, const Transition obj2) 
    { return obj1.getSymbol() < obj2.getSymbol(); };

#endif //TRANSITION_H
