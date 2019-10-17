// Grado en Ingeniería Informática
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 4 CyA - Borrado de comentarios mediante un dfa 
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 14/10/2019
// Archivo main.cpp: Utiliza la clase delete_comments para eliminar los comentarios de un fichero 
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    14/10/2019 - Creación del código



#include <iostream>

#include "delete_comments.h"

int main(int argc, char* argv[]) {
  if(argc != 3)                     // Si se introducen un número de argumentos distintos muestra el mensaje
    std::cout << "MODO DE USO: ./CommentDeleter in.txt out.txt\n"
    "in.txt es el fichero con los comentarios a eliminar\n"
    "out.txt es el fichero sin los comentarios\n";
  else {
    std::ifstream dfa_file("comment.dfa");    // Fichero para inicializar el dfa
    if (dfa_file.is_open()) {
     DeleteComments(dfa_file,argv[1], argv[2]);
    }
     dfa_file.close();
  }
}

