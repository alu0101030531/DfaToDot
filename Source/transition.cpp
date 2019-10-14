#include "transition.h"

Transition::Transition(std::string& symbol, int id): symbol_(symbol), state_id_(id) {
  if (symbol == OTHERSYMBOL)
    any_ = true;
  else
    any_ = false;
}

Transition::Transition(std::string& symbol, std::string& state_id): symbol_(symbol), state_id_(std::stoi(state_id)) {
  if (symbol == OTHERSYMBOL)
    any_ = true;
  else 
    any_ = false;
}

std::ostream& operator<<(std::ostream& os, const Transition& obj) {
  os << obj.symbol_ << " ";
  os << obj.state_id_;
  return os;
}

bool Transition::matchTransition(char symbol) const {
  std::string aux(1,symbol);
  if (symbol_ == aux)
    return true;
  else
    return false;
}
