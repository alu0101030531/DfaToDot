#ifndef STATE_H
#define STATE_H

#include <transition.h>
#include <set>
#include <string>

class State {
 public:
  State(int id, std::set<Transition> transitions, bool accepting_state = false);
  State(std::string& state);
  int getId() const {return id_;};
  bool getAcceptance() const {return accepting_state_;};
  friend std::ostream& operator<<(std::ostream& os, const State& obj);
  int recorreTransitions(char symbol) const;
  int findOtherTransition() const;
 private:
  std::set<Transition> transitions_;
  bool accepting_state_;
  int id_;
};

inline bool operator<(const State& obj1, const State& obj2)
    { return obj1.getId() < obj2.getId();};

#endif //STATE_H
