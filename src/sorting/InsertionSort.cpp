#include "sorting/insertionsort.h"

#include "visuals/visualizer.h"

void InsertionSort(std::vector<int> &arr, sf::RenderWindow &window) {

  for (int i = 1; i < int(arr.size()) && window.isOpen(); i++) {
    int j = i;
    while (j != 0 && window.isOpen()) {
      if (arr[j] < arr[j - 1]) {
        std::swap(arr[j], arr[j - 1]);
        j -= 1;

        sf::sleep(sf::milliseconds(100));
        render(arr, window, "Insertion Sort");
      } else {
        break;
      }
    }
  }
}
