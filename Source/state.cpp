// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Autómata Finito Determinista
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 27/10/2019
// Archivo state.cpp: Clase cuyo fin es representar estados de un dfa, pudiendo obtener su identificador, cambiarlo o
//                  mostrarlo por pantalla
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    27/10/2019 - Creación del código


#include "state.h"

#include <sstream>


// Crea un estado mediante un string
State::State(std::string& state): id_(state) {}

// muestra un estado
std::ostream& operator<<(std::ostream& os, const State& obj) {
  os << obj.id_;
}
