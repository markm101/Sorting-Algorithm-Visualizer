
// https://www.youtube.com/watch?v=MZaf_9IZCrc <- The Goat
#include <vector>

#include "sorting/QuickSort.h"

#include "visuals/visualizer.h"

int partition(std::vector<int> &arr, int low, int high,
              sf::RenderWindow &window) {

  int pivot = arr[high];
  int i = low;

  for (int j = i; j < high; j++) {
    if (arr[j] < pivot) {
      std::swap(arr[i], arr[j]);
      i = i + 1;
      render(arr, window, "Quick Sort");
      sf::sleep(sf::milliseconds(80));
    }
  }
  std::swap(arr[i], arr[high]);

  render(arr, window, "Quick Sort");
  sf::sleep(sf::milliseconds(80));

  return i;
}

void quickMasterSort(std::vector<int> &arr, int low, int high,
                     sf::RenderWindow &window) {
  if (low >= high)
    return;

  int pivotIndex = partition(arr, low, high, window);

  quickMasterSort(arr, low, pivotIndex - 1, window);
  quickMasterSort(arr, pivotIndex + 1, high, window);
}

void quickSort(std::vector<int> &arr, sf::RenderWindow &window) {
  if (arr.size() < 1)
    return;
  quickMasterSort(arr, 0, arr.size() - 1, window);
}
