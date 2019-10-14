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
  Dfa comment_detector_;
  std::ifstream in_file_;
  std::ofstream out_file_;
};
