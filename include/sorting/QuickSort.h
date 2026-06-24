#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

int partition(std::vector<int> &arr, int low, int high);

void quickSort(std::vector<int> &arr, int low, int high);
void quickSort(std::vector<int> &arr, sf::Window &window);
