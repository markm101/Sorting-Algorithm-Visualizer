#include <SFML/Graphics.hpp>

#include <algorithm>
#include <vector>

#include "sorting/selectionsort.h"

int main() {
  sf::RenderWindow window(sf::VideoMode({800, 600}), "Sorting Visualizer");

  std::vector<int> arr = {64, 25, 12, 22, 11, 45, 78, 33, 90, 15};

  while (window.isOpen()) {
    while (auto event = window.pollEvent()) {
      if (event->is<sf::Event::Closed>())
        window.close();
    }

    window.clear();

    int maxValue = *std::max_element(arr.begin(), arr.end());
    // Draw bars here
    for (int i = 0; i < arr.size(); i++) {
      int bar_width = window.getSize().x / arr.size();
      int bar_height =
          (static_cast<float>(arr[i]) / maxValue) * window.getSize().y;
      int x_pos = i * bar_width;
      int y_pos = window.getSize().y - bar_height;

      sf::RectangleShape bar(sf::Vector2f(bar_width, bar_height));

      bar.setPosition(sf::Vector2f(x_pos, y_pos));
      bar.setFillColor(sf::Color::White);
      window.draw(bar);
    }
    window.display();
  }

  return 0;
}
