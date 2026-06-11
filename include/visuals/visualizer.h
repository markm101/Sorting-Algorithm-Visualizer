#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

void render(std::vector<int> &arr, sf::RenderWindow &window,
            const std::string &algoName);
