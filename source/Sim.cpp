#include "Sim.h"

/**
 * Init sim params
 * 
 * 1. Set window to nullptr
 * 2. Set starting food count & max ants
 * 
 * @return void
 */
void Sim::initSim() {
  this->window = nullptr;

  this->startFood = 10000;
  this->maxAnts = 100;
}

/**
 * Init ants
 * 
 * 1. Set ant pos, radius, scale, & color
 * 
 * @return void
 */
void Sim::initAnts() {

  this->ant.setAntPos(sf::Vector2f(10.f, 10.f));
  this->ant.getEntity().setSize(sf::Vector2f(100.f, 100.f));
  this->ant.getEntity().setScale(sf::Vector2f(.5f, .5f));
  this->ant.setAntFill(sf::Color::Red);
}

/**
 * Init food 
 * 
 * 1. Set pos, size ,scale & color
 * 
 * @return void
 */
void Sim::initFood() {
  this->food.setPosition(10.f, 10.f);
  this->food.setSize(sf::Vector2f(10.f,10.f));
  this->food.setScale(.05f, .05f);
}

/**
 * init window
 * 
 * 1. Set width & height
 * 2. init new renderwindow
 * 
 * @return void
 */
void Sim::initWindow() {
  this->vidMode.height = 720;
  this->vidMode.width = 1280;
  this->window = new sf::RenderWindow(this->vidMode, "Ant Colony Simulation", sf::Style::Titlebar | sf::Style::Close);

  this->window->setFramerateLimit(60);
}

/**
 * Sim Constructor
 * 
 * 1. Run initialization
 * 
 * @return None
 */
Sim::Sim() {
  this->initSim();
  this->initWindow();
  this->initAnts();
  // this->initFood();
}

/**
 * Sim Deconstructor
 * 
 * 1. Delete windows
 * 
 * @return none
 */
Sim::~Sim() {
  delete this->window;
}

/**
 * Application status
 * 
 * 1. Check if window is still open
 * 
 * @return const bool
 */
const bool Sim::running() const {
  return this->window->isOpen();
}

/**
 *! Spawns ants at central location - currently random for ant logic testing
 * 
 * 1. Gets ant entity & sets its postion
 * 2. pushes ant to ant vector
 * 
 * @return void
 */
void Sim::spawnAnts() {
  this->ant.setAntPos(
    sf::Vector2f(static_cast<float>(rand() % static_cast<int>(this->window->getSize().x - this->ant.getEntity().getSize().x)),
    static_cast<float>(rand() % static_cast<int>(this->window->getSize().y - this->ant.getEntity().getSize().y))));
  this->ant.setAntFill(sf::Color::Blue);
  this->ants.push_back(this->ant);
}

/**
 * 
 * 
 * @return void
 */
void Sim::updateAnts() {
  // Ant movement logic here
  if(ants.size() < this->maxAnts) {
    this->spawnAnts();
  }
}

/**
 * 
 * 
 * @return void
 */
void Sim::renderAnts() {
  for(auto &a: this->ants) {
    this->window->draw(a.getEntity());
  }
}

/**
 * 
 * 
 * @return void
 */
void Sim::pollEvents() {
  while(this->window->pollEvent(this->ev)) {
    switch (this->ev.type)
    {
    case sf::Event::Closed:
      this->window->close();
      break;

    case sf::Event::KeyPressed:
      if(this->ev.key.code == sf::Keyboard::Escape) {
        this->window->close();
      }
      break;

    default:
      break;
    }
  }
}

/**
 * Updates all sim events & entities
 * 
 * 1. poll events
 * 2. update sim objects
 * 
 * @return void
 */
void Sim::update() {
  this->pollEvents();
  this->updateAnts();
}

/**
 * Renders the frame
 * 
 * 1. Clear old frame
 * 2. render objects
 * 3. display new frame
 * 
 * @return void
 */
void Sim::render() {
  this->window->clear(sf::Color::Black);

  this->renderAnts();

  this->window->display();
}