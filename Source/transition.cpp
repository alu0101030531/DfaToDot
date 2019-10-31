/**
  Grado en Ingeniería Informática
   Asignatura: Computabilidad y Algoritmia (CyA)
   Curso: 2º 
   Práctica 3 CyA - Calculadora de lenguajes regulares
   Autor: Christian Jesús Pérez Hernández
   Correo: alu0101030531@ull.edu.es
   Fecha: 14/10/2019
   Archivo transition.cpp: Define la clase transition, esta consta de dos constructores que construyen a partir de un
                           símbolo y de dos estados uno de destino y otro el de salida y otro constructor que construye
                           a partir de una string, para ello debe estar bien formateada habiendo un espacio entre cada
                           valor, una método "matchTransition" que determina el estado de llegada según un estado de
                           salida y un símbolo
   Referencias: 
                      Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
   Historial de revisiones
                      27/10/2019 - Creación del código
*/

#include "transition.h"
#include <iostream>

/** Crea una transición con un símbolo y un identificador */
Transition::Transition(char symbol, State from_state, State to_state): symbol_(symbol), from_state_(from_state),
    to_state_(to_state) {}

/** Crea una transición con dos strings */
Transition::Transition(std::string& transition) {
  std::stringstream ss(transition);
  std::string item;                   /** almacena los estados */
  ss >> item;
  from_state_.setId(item);
  ss >> symbol_;
  ss >> item;
  to_state_.setId(item);
}

/** Muestra una transición */
std::ostream& operator<<(std::ostream& os, const Transition& obj) {
  os << "\"" << obj.from_state_ << "\"" << " -> ";
  os << "\"" << obj.to_state_ << "\""<< " [ label=\"";
  os << obj.symbol_ << "\" ];";
  return os;
}

/** Devuelve true si transiciona con symbol */
bool Transition::matchTransition(State from_state, char symbol) {
  return (symbol == symbol_ && from_state == from_state_)? true : false; 
}

/** Operador < */
bool operator<(const Transition& obj1, const Transition obj2) {
  std::string left_str = obj1.getPrevState().getId() + obj1.getSymbol() + obj1.getNextState().getId();
  std::string right_str = obj2.getPrevState().getId() + obj2.getSymbol() + obj2.getNextState().getId();
  return left_str < right_str;
}
