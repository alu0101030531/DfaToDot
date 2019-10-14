#ifndef TRANSITION_H
#define TRANSITION_H

#include <stdio.h>
#include <string>
#include <sstream>
#include <iostream>

const std::string OTHERSYMBOL = "other";

class Transition {
 public:
  Transition(std::string& symbol, int id);
  Transition(std::string& symbol, std::string& state_id);
  std::string getSymbol() const {return symbol_;}; 
  int getNextId() const {return state_id_;};
  bool hasAnyTransition() const {return any_;};
  friend std::ostream& operator<<(std::ostream& os, const Transition& obj);
  bool matchTransition(char symbol) const;
 private:
  std::string symbol_;
  int state_id_;
  bool any_;
};

inline bool operator<(const Transition& obj1, const Transition obj2) 
    { return obj1.getSymbol() < obj2.getSymbol(); };

#endif //TRANSITION_H
