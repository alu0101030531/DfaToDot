// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios usando un dfa
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 6/10/2019
// Archivo delete_comments.cpp: Archivo Cpp con las definiciones de la clase:
//                      
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    6/10/2019 - Creación del código

#include "delete_comments.h"

#include <iostream>

// Crea un clase para analizar y borrar los comentarios
DeleteComments::DeleteComments(std::ifstream& dfa_file, std::string in_file, std::string out_file): in_file_(in_file), out_file_(out_file),
    comment_detector_(dfa_file) {
  if (in_file_.is_open() && out_file_.is_open())
    catchAndDelete();
  else
    std::cout << "Error abriendo los ficheros\n";
}

// Cierra los descriptores del fichero
DeleteComments::~DeleteComments() {
  in_file_.close();
  out_file_.close();
}

// Coge caracteres del fichero y los analiza en el dfa
void DeleteComments::catchAndDelete() {
  char symbol;
  std::string line;
  State prev_state(comment_detector_.getActualState());
  while (in_file_.get(symbol)) {
    comment_detector_.recorreDfa(symbol);
    State actual_state(comment_detector_.getActualState());
    if (actual_state.getAcceptance()) {
      if (commentDetected(prev_state, actual_state))
        line.pop_back();
    } else {
      if (!commentDetected(prev_state, actual_state))
      line += symbol;
    }
    if (symbol == '\n'){
      out_file_ << line;
      line.clear();
    }
    prev_state = actual_state;
  }
}

// Si detecta un comentario devuelve true
bool DeleteComments::commentDetected(const State& prev_state, const State& next_state) {
  bool is_comment = false;
  switch (prev_state.getId()) {
    case 1:
      if (next_state.getId() == 2 || next_state.getId() == 3)
        is_comment = true;
        break;
    case 4:
      if (next_state.getId() == 0)
        is_comment = true;
        break;
  }
  return is_comment;
}
