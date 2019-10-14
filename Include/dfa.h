#ifndef DFA_H
#define DFA_H

#include "state.h"
#include <fstream>

class Dfa {
 public:
  Dfa(std::set<State> states, int start);
  Dfa(std::ifstream& dfa_file);
  friend std::ostream& operator<<(std::ostream& os, const Dfa& obj);
  void recorreDfa(char symbol);
  State getActualState() { return *dfa_pos_;};
 private:
  std::set<State>::iterator match(int id);
 private:
  std::set<State> states_;
  int start_;
  std::set<State>::iterator dfa_pos_;
};

#endif // DFA_H
