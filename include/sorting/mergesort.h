#pragma once
#include <SFML/Graphics.hpp>

#include <vector>

void inner_merge(std::vector<int> &arr, int left, int right,
                 sf::RenderWindow &window);

void outer_merge(std::vector<int> &arr, int left, int right,
                 sf::RenderWindow &window);

void MergeSort(std::vector<int> &arr, sf::RenderWindow &window);
