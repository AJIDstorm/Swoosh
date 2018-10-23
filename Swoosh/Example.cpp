// Swoosh.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <SFML/Window.hpp>
#include "ActivityController.h"
#include "MainMenuScene.h"
int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Swoosh - Mini App Segue Framework");
  window.setFramerateLimit(60); // call it once, after creating the window
  window.setVerticalSyncEnabled(true);

  ActivityController app(window);
  app.Push<MainMenuScene>();

  // run the program as long as the window is open
  float elapsed = 0.0f;
  sf::Clock clock;

  srand((unsigned int)time(0));

  while (window.isOpen())
  {
    clock.restart();

    // check all the window's events that were triggered since the last iteration of the loop
    sf::Event event;
    while (window.pollEvent(event))
    {
      // "close requested" event: we close the window
      if (event.type == sf::Event::Closed)
        window.close();
    }

    app.Update(elapsed);
    app.Draw();
    window.display();
    //window.clear();

    elapsed = static_cast<float>(clock.getElapsedTime().asMilliseconds());
  }

  return 0;
}