#include <SFML/Graphics.hpp>
#include <cstdlib>

#include <functional>

#include "sorting/QuickSort.h"
#include "sorting/bubblesort.h"
#include "sorting/insertionsort.h"
#include "sorting/mergesort.h"
#include "sorting/selectionsort.h"

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Sorting Visualizer");

  std::vector<int> arr = {64, 25, 12, 22, 11,  45, 78, 33, 90,
                          15, 20, 50, 80, 100, 2,  1,  5,  8};
  std::vector<int> newarr = arr;
  std::function<void(std::vector<int> &, sf::RenderWindow &)> lastAlgo =
      nullptr;
  srand(time(0));
  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();

      // Algorithm Events

      if (event->is<sf::Event::KeyPressed>()) {
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num1) {
          lastAlgo = selectionSort;
          newarr = arr;
          selectionSort(newarr, window);
        }
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num2) {
          lastAlgo = BubbleSort;
          newarr = arr;
          BubbleSort(newarr, window);
        }
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num3) {
          lastAlgo = InsertionSort;
          newarr = arr;
          InsertionSort(newarr, window);
        }
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num4) {
          lastAlgo = MergeSort;
          newarr = arr;
          MergeSort(newarr, window);
        }
        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::Num5) {
          lastAlgo = quickSort;
          newarr = arr;
          quickSort(newarr, window);
        }

        // Misc Events

        if (event->getIf<sf::Event::KeyPressed>()->code ==
            sf::Keyboard::Key::R) {
          for (int i = 0; i < arr.size(); i++) {
            arr[i] = rand() % 100 + 1;
          }
          if (lastAlgo) {
            newarr = arr;
            lastAlgo(newarr, window);
          }
        }
      }
    }
  }

  return 0;
}
