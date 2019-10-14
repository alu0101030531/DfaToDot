#include "state.h"

#include <sstream>

State::State(int id, std::set<Transition> transitions, bool accepting_state): transitions_(transitions),
    accepting_state_(accepting_state), id_(id) {}

State::State(std::string& state) {
  std::stringstream ss(state);
  std::string token;
  ss >> token;
  id_ = std::stoi(token);
  ss >> token;
  if(token == "0")
    accepting_state_ = false;
  else
    accepting_state_ = true;
  int last;
  ss >> last;
  std::string state_id;
  for (int i = 0; i < last; i++) {
    ss >> token;
    if (token == "\\n")
      token = "\n";
    ss >> state_id;
    transitions_.insert({token, state_id});
  }
}

std::ostream& operator<<(std::ostream& os, const State& obj) {
  os << obj.id_ << " ";
  for (const auto& it : obj.transitions_)
    os << it << " ";
  return os;
}

int State::recorreTransitions(char symbol) const {
  for (const auto& it : transitions_) {
    if (it.matchTransition(symbol)) {
      return it.getNextId();
    }
  } 
 return findOtherTransition();
} 

int State::findOtherTransition() const {
  for (const auto& it : transitions_) {
    if (it.hasAnyTransition())
      return it.getNextId();
  }
}
