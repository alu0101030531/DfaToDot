// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios usando un dfa
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo state.cpp: Definiciones de la clase state
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código


#include "state.h"

#include <sstream>

// Crea un estado con un conjunto de transiciones y un booleano indicando si es un estado final
State::State(int id, std::set<Transition> transitions, bool accepting_state): transitions_(transitions),
    accepting_state_(accepting_state), id_(id) {}

// Crea un estado mediante un string
State::State(std::string& state) {
  std::stringstream ss(state);
  std::string token;
  ss >> token;
  id_ = std::stoi(token);
  ss >> token;
  if(token == "0")
    accepting_state_ = false;
  else
    accepting_state_ = true;
  int last;
  ss >> last;
  std::string state_id;
  for (int i = 0; i < last; i++) {
    ss >> token;
    if (token == "\\n")
      token = "\n";
    ss >> state_id;
    transitions_.insert({token, state_id});
  }
}

// muestra un estado
std::ostream& operator<<(std::ostream& os, const State& obj) {
  os << obj.id_ << " ";
  for (const auto& it : obj.transitions_)
    os << it << " ";
  return os;
}

// Recorre las transiciones para comprobar si symbol suple alguna de ella
int State::recorreTransitions(char symbol) const {
  for (const auto& it : transitions_) {
    if (it.matchTransition(symbol)) {     // Si suple alguna de las transiciones
      return it.getNextId();
    }
  } 
 return findOtherTransition();
} 

// Devuelve si existe la transición que transiciona con cualquiera
int State::findOtherTransition() const {
  for (const auto& it : transitions_) {
    if (it.hasAnyTransition())
      return it.getNextId();
  }
}
