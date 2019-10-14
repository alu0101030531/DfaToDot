#include "delete_comments.h"

#include <iostream>

DeleteComments::DeleteComments(std::ifstream& dfa_file, std::string in_file, std::string out_file): in_file_(in_file), out_file_(out_file),
    comment_detector_(dfa_file) {
  if (in_file_.is_open() && out_file_.is_open())
    catchAndDelete();
  else
    std::cout << "Error abriendo los ficheros\n";
}

DeleteComments::~DeleteComments() {
  in_file_.close();
  out_file_.close();
}

void DeleteComments::catchAndDelete() {
  char symbol;
  std::string line;
  State prev_state(comment_detector_.getActualState());
  std::cout << prev_state.getId() << "\n";
  while (in_file_.get(symbol)) {
    comment_detector_.recorreDfa(symbol);
    State actual_state(comment_detector_.getActualState());
    std::cout << prev_state.getId() << " " << actual_state.getId() << " " << symbol<<"\n";
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

    //Recorres con el simbolo
    //si no es un estado de aceptación
    //almacenas en un string
    //si es un estado de aceptación y el ultimo / pop del último
    // si es salto de linea escribe

