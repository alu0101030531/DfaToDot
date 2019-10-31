/**
  Grado en Ingeniería Informática
   Asignatura: Computabilidad y Algoritmia (CyA)
   Curso: 2º 
   Práctica 6- Autómata Finito Determinista
   Autor: Christian Jesús Pérez Hernández
   Correo: alu0101030531@ull.edu.es
   Fecha: 30/10/2019
   Archivo alfabeto.cpp: Se define el constructor de un alfabeto que inicializa symbols con un set de char y 
                        El método para mostrar por pantalla de la forma "{a,b}"
          
                 
   Referencias: 
                      Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
   Historial de revisiones      26/10/2019 - Creación del código
*/

#include "alfabeto.h"

/** Construye un alfabeto a partir de un set de símbolos */
Alfabeto::Alfabeto(std::set<char> symbols): symbols_(symbols) {}

/** Muestra un alfabeto */
std::ostream& operator<<(std::ostream& os, const Alfabeto& obj) {
  std::set<char>::iterator it = obj.symbols_.begin();
  std::set<char>::iterator flag_last_item = obj.symbols_.end();
  flag_last_item--;   /** itera hasta el penúltimo símbolo del alfabeto */
  os << "{";
  for (;it != flag_last_item; ++it)
    os << *it << ", ";
  it++;   /** Aumenta hasta el último símbolo */
  os << *it <<"}"; 
}
