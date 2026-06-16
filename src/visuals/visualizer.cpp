#include <algorithm>

#include "visuals/visualizer.h"

void render(std::vector<int> &arr, sf::RenderWindow &window,
            const std::string &algoName) {

  while (auto event = window.pollEvent()) {
    if (event->is<sf::Event::Closed>())
      window.close();
  }

  window.clear();

  sf::Color barColor = sf::Color::White;
  sf::Color highlighted = sf::Color::Red;
  sf::Color finalized = sf::Color::Green;

  // Text Params
  sf::Font font(
      "../assets/fonts/Roboto-Bold.ttf"); // can't be static w/o crashing
                                          // and needs a new approach

  sf::Text text(font, algoName, 24);
  text.setPosition(sf::Vector2f(10.f, 10.f));
  text.setFillColor(sf::Color::White);

  // Bar Rendering
  int maxValue = *std::max_element(arr.begin(), arr.end());

  for (int i = 0; i < int(arr.size()); i++) {
    float space_width = static_cast<float>(window.getSize().x) / arr.size();
    float bar_width = space_width * 0.8f; // 80% bar, 20% gap
    float bar_height =
        (static_cast<float>(arr[i]) / maxValue) * window.getSize().y;
    float x_pos = i * space_width;
    float y_pos = window.getSize().y - bar_height;

    // Adjust Bar Width and Bar Height with Ratios

    sf::RectangleShape bar(sf::Vector2f(bar_width, bar_height));
    sf::Text label(font, std::to_string(arr[i]), 20);

    bar.setPosition(sf::Vector2f(x_pos, y_pos));
    label.setPosition(sf::Vector2f(x_pos, y_pos));
    bar.setFillColor(barColor);
    label.setFillColor(sf::Color::Black);
    window.draw(bar);
    window.draw(label);
  }
  window.draw(text);
  window.display();
}
