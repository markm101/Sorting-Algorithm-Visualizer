#include "visuals/visualizer.h"

#include "sorting/bubblesort.h"
#include "sorting/selectionsort.h"

void render(std::vector<int> &arr, sf::RenderWindow &window) {

  while (auto event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      window.close();
  }

  window.clear();

  sf::Color barColor = sf::Color::White;
  sf::Color highlighted = sf::Color::Red;
  sf::Color finalized = sf::Color::Green;

  // Bar Rendering
  int maxValue = *std::max_element(arr.begin(), arr.end());

  for (int i = 0; i < arr.size(); i++) {
    float space_width = static_cast<float>(window.getSize().x) / arr.size();
    float bar_width = space_width * 0.8f; // 80% bar, 20% gap
    float bar_height =
        (static_cast<float>(arr[i]) / maxValue) * window.getSize().y;
    float x_pos = i * space_width;
    float y_pos = window.getSize().y - bar_height;

    // Adjust Bar Width and Bar Height with Ratios

    sf::RectangleShape bar(sf::Vector2f(bar_width, bar_height));

    bar.setPosition(sf::Vector2f(x_pos, y_pos));
    bar.setFillColor(barColor);
    window.draw(bar);
  }
  window.display();
}

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
