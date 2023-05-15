#include "Sim.h"

int main() {
  std::srand(static_cast<unsigned>(time(NULL)));

  Sim sim;
  while(sim.running()){
    sim.update();
    sim.render();
  }

  return 0;
}