// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios usando un dfa 
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 6/10/2019
// Archivo delete_comments.h: Borra los comentarios de un fichero 
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    6/10/2019 - Creación del código
#ifndef DELETE_COMMENTS_H
#define DELETE_COMMENTS_H

#include "dfa.h"


#include <string>
#include <fstream>

class DeleteComments {
 public:
  DeleteComments(std::ifstream& dfa_file, std::string in_file, std::string out_file);
  ~DeleteComments();
  void catchAndDelete();
  bool commentDetected(const State& prev_state, const State& next_state);
 private:
  Dfa comment_detector_;      // Dfa para detectar los comentarios del fichero
  std::ifstream in_file_;     // Fichero de entrada a analizar
  std::ofstream out_file_;    // Fichero donde se escribe el resultado
};

#endif // DELETE_COMMENTS_H
