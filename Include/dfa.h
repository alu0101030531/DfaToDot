// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios mediante un dfa 
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo dfa.h: Permite crear un dfa dado un fichero
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código


#ifndef DFA_H
#define DFA_H

#include "state.h"
#include <fstream>

class Dfa {
 public:
  Dfa(std::set<State> states, int start);
  Dfa(std::ifstream& dfa_file);
  friend std::ostream& operator<<(std::ostream& os, const Dfa& obj);
  void recorreDfa(char symbol);
  State getActualState() { return *dfa_pos_;};
 private:
  std::set<State>::iterator match(int id);
 private:
  std::set<State> states_;              // Conjunto de estados del dfa
  int start_;                           // Identificador del estado inicial
  std::set<State>::iterator dfa_pos_;   // Posición en la que se encuentra el dfa
};

#endif // DFA_H
