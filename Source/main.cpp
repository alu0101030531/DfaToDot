/**
  Grado en Ingeniería Informática
   Asignatura: Computabilidad y Algoritmia (CyA)
   Curso: 2º 
   Práctica 6 CyA - Automata finito determinista
   Autor: Christian Jesús Pérez Hernández
   Correo: alu0101030531@ull.edu.es
   Fecha: 27/10/2019
   Archivo main.cpp: Inicializa un dfa mediante un fichero para obtener un fichero dot que permita la visualización
                     gráfica del dfa 
                       
                   
   Referencias: 
                      Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
   Historial de revisiones
                      27/10/2019 - Creación del código
*/


#include <iostream>
#include <fstream>
#include <cstring>

#include "dfa.h"

/** Muestra el modo de uso */
void showinfo() {
  std::cout << "Modo de empleo: ./DFA2dot input.dfa output.gv\n"
  "Pruebe ’DFA2dot --help’ para más información.\n";
}

/** Muestra el modo de uso avanzado */
void showhelpinfo() {
  std::cout << " --> input.dfa: fichero que define un dfa\n"
  " --> output.gv: fichero DOT con el diagrama de transiciones del DFA\n";
}

int main(int argc, char* argv[]) {
  switch (argc) {
    case 0:
    case 1:
      showinfo();
      break;
    case 2:
      if(strcmp("--help", argv[1]) == 0)
        showhelpinfo();
    case 3:
    std::ifstream dfa_file(argv[1]);
    std::ofstream out(argv[2]);
    if (dfa_file.is_open() && out.is_open()) {
      Dfa automata(dfa_file);
      automata.dfaToDot(out);
    }
     dfa_file.close();
     out.close();
  }
}

