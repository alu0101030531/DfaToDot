#include <iostream>

#include "delete_comments.h"

int main(int argc, char* argv[]) {
  if(argc != 3)
    std::cout << "MODO DE USO:\n";
  else {
    std::ifstream dfa_file("comment.dfa");
    if (dfa_file.is_open()) {
     DeleteComments(dfa_file,argv[1], argv[2]);
    }
     dfa_file.close();
  }
}

