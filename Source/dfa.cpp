
// Asignatura: Computabilidad y Algoritmia (CyA)
// Curso: 2º 
// Práctica 6 CyA - Autómata Finito Determinista
// Autor: Christian Jesús Pérez Hernández
// Correo: alu0101030531@ull.edu.es
// Fecha: 27/10/2019
// Archivo dfa.cpp: Define la clase dfa, permite construir un dfa dado un fichero, recorrer el dfa para un cadena dada,
//                  este método a su vez llama a la función recorrerDfa que es la función de transición del dfa, para la
//                  cual dado un estado y un símbolo mueve el iterador dfa_pos al estado al que transiciona, también
//                  cuenta con un método que convierte un dfa en un fichero.gv que puede ser interpretado como un
//                  fichero gráfico gracias a Graphviz
//                     
//                 
// Referencias: 
//                    Enunciado de la práctica: https://campusvirtual.ull.es/1920/mod/assign/view.php?id=103940
// Historial de revisiones
//                    27/10/2019 - Creación del código



#include "dfa.h"

#include <stdexcept>
#include <string>

// Construye un dfa dado un fichero
Dfa::Dfa(std::ifstream& dfa_file) {
  if (dfa_file.is_open()) {
    std::string line;
    std::set<char> symbols;
    getline(dfa_file, line);
    while (std::regex_match(line, COMMENT))
      getline(dfa_file, line);
    int max_items = std::stoi(line);        // Número de transiciones, estados y símbolos del alfabeto
    for (int i = 0; i < max_items; i++) {   // Inicializa los símbolos
      getline(dfa_file, line);
      symbols.insert(line[0]);
    }
    alphabet_.setAlphabet(symbols);
    getline(dfa_file, line);
    max_items = std::stoi(line);
    for (int i = 0; i < max_items; i++) {   // Inicializa los estados
      getline(dfa_file, line);
      states_.insert(line);
    }
    getline(dfa_file, line);
    starting_state_.setId(line);
    getline(dfa_file, line);
    max_items = std::stoi(line);
    for (int i = 0; i < max_items; i++) {   // Inicializa los estados de aceptación
      getline(dfa_file, line);
      accepting_states_.insert(line);
    }
    getline(dfa_file, line);
    max_items = std::stoi(line);
    for (int i = 0; i < max_items; i++) {
      getline(dfa_file, line);
      transitions_.insert(line);
    }
    dfa_pos_ = dfaBegin();
  }
  else
    std::cout << "error abriendo el fichero\n";
}

// Devuelve un iterador apuntando al estado inicial
std::set<State>::iterator Dfa::dfaBegin() {
  std::set<State>::iterator it = states_.begin();
  for (; it != states_.end(); it++) {
    if (*it == starting_state_)
      return it;
  }
}

// Devuelve si es un estado de aceptación
bool Dfa::acceptingState() {
  for (const auto& it : accepting_states_) {
    if (*dfa_pos_ == it)
      return true;
  }
  return false;
}

// Dada una cadena recorre el dfa devolviendo si es aceptada o no
bool Dfa::recorreDfa(std::string& chain) {
  for (int i = 0; i < chain.size(); i++) {
    bool stop_flag = recorreDfa(chain[i]);
    if (stop_flag)
      return false;
  }
  return acceptingState();
}

// Dado un símbolo recorre el dfa devolviendo si lo acepta o no
bool Dfa::recorreDfa(char symbol) {
  for (auto it : transitions_) {
    if (it.matchTransition(*dfa_pos_, symbol)) {
      dfa_pos_ = match(it.getNextState());
      return false;
    }
  }
  return true;
}

// Convierte el dfa a un fichero .dot para generar un grafo que represente al dfa
void Dfa::dfaToDot(std::ofstream& graphic_file) {
  graphic_file << GRAPHSETTINGS;
  for (const auto& state : accepting_states_) {
    graphic_file << "\"";
    graphic_file << state << "\"" << " ";
  }
  graphic_file << ";\n";
  graphic_file << BOTTOMGRAPHSETTINGS;

  for (const auto& transition : transitions_)
    graphic_file << transition << "\n";

  graphic_file << "}";
}

// Devuelve un iterador apuntando a un estado del conjunto
std::set<State>::iterator Dfa::match(State next_state) {
  std::set<State>::iterator it = states_.begin();
  for (; it != states_.end(); it++) {
    if (next_state == *it)
      return it;
  }
  return dfa_pos_;
}
