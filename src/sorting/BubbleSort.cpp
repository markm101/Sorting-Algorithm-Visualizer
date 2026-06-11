#include "sorting/bubblesort.h"

void BubbleSort(std::vector<int> &arr, sf::RenderWindow &window) {

  bool has_Swap = true;
  while (has_Swap == true) {
    has_Swap = false;
    for (int i = 0; i < (int(arr.size()) - 1); i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        has_Swap = true;
        sf::sleep(sf::milliseconds(100)); // For visualization
        render(arr, window);
      }
    }
  }
}
