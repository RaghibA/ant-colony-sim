#ifndef SIM_H
#define SIM_H

#include <iostream>
#include <vector>
#include <ctime>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

#include "Ant.h"

class Sim
  {
private:
  sf::RenderWindow *window;
  sf::VideoMode vidMode;
  sf::Event ev;

  int startFood;
  int maxAnts;

  std::vector<Ant> ants;
  Ant ant;

  std::vector<sf::RectangleShape> feed;
  sf::RectangleShape food;

  void initSim();
  void initAnts();
  void initFood();
  void initWindow();

public:
  Sim();
  ~Sim();

  const bool running() const;

  void spawnAnts();
  void updateAnts();
  void renderAnts();

  // void spawnFood();
  // void updateFood();
  // void renderFood();

  void pollEvents();
  void update();
  void render();
};

#endif