// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 3 CyA - Calculadora de lenguajes regulares
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo transition.cpp: Define la clase transition 
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código


#include "transition.h"

// Crea una transición con un símbolo y un identificador
Transition::Transition(std::string& symbol, int id): symbol_(symbol), state_id_(id) {
  if (symbol == OTHERSYMBOL)
    any_ = true;
  else
    any_ = false;
}

// Crea una transición con dos strings
Transition::Transition(std::string& symbol, std::string& state_id): symbol_(symbol), state_id_(std::stoi(state_id)) {
  if (symbol == OTHERSYMBOL)
    any_ = true;
  else 
    any_ = false;
}

// Muestra una transición
std::ostream& operator<<(std::ostream& os, const Transition& obj) {
  os << obj.symbol_ << " ";
  os << obj.state_id_;
  return os;
}

// Devuelve true si transiciona con symbol
bool Transition::matchTransition(char symbol) const {
  std::string aux(1,symbol);
  if (symbol_ == aux)
    return true;
  else
    return false;
}
