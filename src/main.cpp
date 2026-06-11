#include <SFML/Graphics.hpp>

#include "sorting/bubblesort.h"
#include "sorting/selectionsort.h"

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Sorting Visualizer");

  std::vector<int> arr = {64, 25, 12, 22, 11,  45, 78, 33, 90,
                          15, 20, 50, 80, 100, 2,  1,  5,  8};
  std::vector<int> newarr = arr;

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
      if (event->is<sf::Event::KeyPressed>()) {
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num1) {
          newarr = arr;
          selectionSort(newarr, window);
        }
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num2) {
          newarr = arr;
          BubbleSort(newarr, window);
        }
      }
    }
  }

  return 0;
}
