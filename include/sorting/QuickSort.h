#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

int partition(std::vector<int> &arr, int low, int high,
              sf::RenderWindow &window);

void quickMasterSort(std::vector<int> &arr, int low, int high,
                     sf::RenderWindow &window);
void quickSort(std::vector<int> &arr, sf::RenderWindow &window);
