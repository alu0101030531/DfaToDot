#include "dfa.h"

#include <stdexcept>
#include <string>

// Construye un dfa a partir de un conjunto de estados
Dfa::Dfa(std::set<State> states, int start): states_(states), start_(start), dfa_pos_(states_.begin()) {}
   /* prev_pos_(states_.begin())*/ 

// Construye un dfa dado un fichero
Dfa::Dfa(std::ifstream& dfa_file) {
  if (dfa_file.is_open()) {
    std::string line;
    getline(dfa_file, line);
    start_ = std::stoi(line);
    while (getline(dfa_file, line)) 
      states_.insert(line);
    dfa_pos_ = states_.begin();
   // prev_pos_ = states_.begin();
  }
  else
    std::cout << "error abriendo el fichero\n";
}

// Muestra el dfa
std::ostream& operator<<(std::ostream& os, const Dfa& obj) {
  os << obj.states_.size() << "\n";
  os << obj.start_ << "\n";
  for (const auto& it : obj.states_) 
    os << it << "\n";
  return os;
}

void Dfa::recorreDfa(char symbol) {
  int id   = dfa_pos_->recorreTransitions(symbol);
  dfa_pos_ = match(id);
}

std::set<State>::iterator Dfa::match(int id) {
  std::set<State>::iterator it = states_.begin();
  for (; it != states_.end(); it++) {
    if (id == it->getId())
      return it;
  }
  return dfa_pos_;
}
