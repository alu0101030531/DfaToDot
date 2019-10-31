/**
    Grado en Ingeniería Informática
  Asignatura: Computabilidad y Algoritmia (CyA)
   Curso: 2º 
   Práctica 6 CyA - Autómatas finitos deterministas
   Autor: Christian Jesús Pérez Hernández
   Correo: alu0101030531@ull.edu.es
   Fecha: 27/10/2019
   Archivo transition.h: Define las transiciones de un dfa dado un estado y un símbolo y el estado al que transiciona  
                         Permite obtener dado un simbolo y un estado, conocer a que estado transiciona     
                       
                   
   Referencias: 
                      Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=117994
   Historial de revisiones
                      27/10/2019 - Creación del código
*/

#ifndef TRANSITION_H
#define TRANSITION_H

#include "state.h"

#include <string>
#include <sstream>
#include <iostream>

/** 
  Modo de Uso:
 Transition transicion("q1 a q2");
 std::cout << transicion << "\n";
 */
class Transition {
 public:
  Transition() {};
  Transition(char symbol, State from_state, State to_state);
  Transition(std::string& transition);
  friend std::ostream& operator<<(std::ostream& os, const Transition& obj);
  bool matchTransition(State from_state, char symbol);
  char getSymbol() const {return symbol_;}; 
  State getPrevState() const {return from_state_;};
  State getNextState() const {return to_state_;};
 private:
  char symbol_;        /** Guarda el símbolo de la transición */
  State from_state_;          /** Estado del que transiciona */  
  State to_state_;            /** Estado al que transiciona */
};

bool operator<(const Transition& obj1, const Transition obj2);

#endif /** TRANSITION_H */
