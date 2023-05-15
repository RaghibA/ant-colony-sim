#ifndef ANT_H
#define ANT_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>

class Ant
{
private:
  sf::RectangleShape entity;
  sf::Vector2f position;

public:

  sf::Vector2f getPosition();

  void setAntPos(sf::Vector2f pos) { this->entity.setPosition(pos); }
  void setAntSize(sf::Vector2f size) { this->entity.setSize(size); }
  void setAntScale(sf::Vector2f scale) { this->entity.setScale(scale); }
  void setAntFill(sf::Color color) { this->entity.setFillColor(color); }

  sf::RectangleShape getEntity() {return this->entity;}
};

#endif