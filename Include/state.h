/**
  Grado en Ingeniería Informática
   Asignatura: Computabilidad y Algoritmia (CyA)
   Curso: 2º 
   Práctica 6 CyA - Autómata Finito Determinista
   Autor: Christian Jesús Pérez Hernández
   Correo: alu0101030531@ull.edu.es
   Fecha: 27/10/2019
   Archivo state.h: Clase cuyo fin es representar estados de un dfa, pudiendo obtener su identificador, cambiarlo o
                    mostrarlo por pantalla
                       
                   
   Referencias: 
                      Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
   Historial de revisiones
                      27/10/2019 - Creación del código
*/

#ifndef STATE_H
#define STATE_H

#include <set>
#include <string>

/**
  Modo De Uso:
     State estado1("q1");
     std::cout << estado1 << "\n";
*/
class State {
 public:
  State() {};
  State(std::string& state);
  friend std::ostream& operator<<(std::ostream& os, const State& obj);
  void setId(std::string id) {id_ = id;};
  std::string getId() const {return id_;};
 private:
  std::string id_;                              /** Identificador del estado */
};

inline bool operator<(const State& obj1, const State& obj2)
    {return obj1.getId() < obj2.getId();};

inline bool operator==(const State& obj1, const State& obj2) 
    {return obj1.getId() == obj2.getId();}; 
#endif /** STATE_H */
