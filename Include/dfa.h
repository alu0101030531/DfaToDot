// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Autómata Finito Determinista
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 27/10/2019
// Archivo dfa.h: Define la clase dfa, permite construir un dfa dado un fichero, recorrer el dfa para un cadena dada,
//                este método a su vez llama a la función recorrerDfa que es la función de transición del dfa, para la
//                cual dado un estado y un símbolo mueve el iterador dfa_pos al estado al que transiciona, también
//                cuenta con un método que convierte un dfa en un fichero.gv que puede ser interpretado como un
//                fichero gráfico gracias a Graphviz
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    27/10/2019 - Creación del código


#ifndef DFA_H
#define DFA_H

#include "state.h"
#include "transition.h"
#include "alfabeto.h"
#include <fstream>
#include <regex>

const std::regex COMMENT("\\/\\/.*");     // Expresión regular que identifica los comentarios

const std::string GRAPHSETTINGS = "digraph DFA {\nrankdir=LR;\nsize = \"10, 4\";\nd2tstyleonly = true;\nnode [shape ="
    " none]; \"\";\nnode [shape = doublecircle]; ";                               // Configuración del fichero .dot
const std::string BOTTOMGRAPHSETTINGS = "node [shape = circle];\n";               // Configuración del fichero .dot


class Dfa {
 public:
  Dfa(std::ifstream& dfa_file);
  friend std::ostream& operator<<(std::ostream& os, const Dfa& obj);
  State getActualState() { return *dfa_pos_;};
  bool recorreDfa(std::string& chain);
  void dfaToDot(std::ofstream& graphic_file);
  std::string getFinalState() {return dfa_pos_->getId();};
 private:
  bool acceptingState();
  bool recorreDfa(char symbol);                     // Función de transición
  std::set<State>::iterator match(State next_state);
  std::set<State>::iterator dfaBegin();
 private:
  Alfabeto alphabet_;                   // Alfabeto del dfa
  std::set<State> states_;              // Conjunto de estados del dfa
  std::set<State> accepting_states_;    // Conjunto de estados de aceptación
  State starting_state_;                // Estado inicial
  std::set<Transition> transitions_;    // Transiciones para cada estado del dfa
  std::set<State>::iterator dfa_pos_;   // Posición en la que se encuentra el dfa
};

#endif // DFA_H
