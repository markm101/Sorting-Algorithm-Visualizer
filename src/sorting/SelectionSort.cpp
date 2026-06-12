#include "sorting/selectionsort.h"

#include "visuals/visualizer.h"

void selectionSort(std::vector<int> &arr, sf::RenderWindow &window) {

  for (int i = 0; i < int(arr.size()) && window.isOpen(); i++) {
    int minindex = i;
    for (int p = i + 1; p < int(arr.size()); p++) {
      if (arr[minindex] > arr[p]) {
        minindex = p;
      }
    }
    std::swap(arr[i], arr[minindex]);

    sf::sleep(sf::milliseconds(100)); // For visualization
    render(arr, window, "Selection Sort");
  }
}
