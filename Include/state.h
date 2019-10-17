// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios mediante un dfa 
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo state.h: Crea un estado de un dfa
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código


#ifndef STATE_H
#define STATE_H

#include <transition.h>
#include <set>
#include <string>

class State {
 public:
  State(int id, std::set<Transition> transitions, bool accepting_state = false);
  State(std::string& state);
  int getId() const {return id_;};
  bool getAcceptance() const {return accepting_state_;};    // Devuelve si es un estado de aceptación
  friend std::ostream& operator<<(std::ostream& os, const State& obj);
  int recorreTransitions(char symbol) const;
 private:
  int findOtherTransition() const;
 private:
  std::set<Transition> transitions_;    // Conjunto de transiciones de un estado
  bool accepting_state_;                // 1: si es un estado de aceptación
  int id_;                              // Identificador del estado
};

inline bool operator<(const State& obj1, const State& obj2)
    { return obj1.getId() < obj2.getId();};

#endif //STATE_H
