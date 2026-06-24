
// https://www.youtube.com/watch?v=MZaf_9IZCrc <- The Goat
#include <vector>

#include "sorting/QuickSort.h"

#include "visuals/visualizer.h"

int partition(std::vector<int> &arr, int low, int high, sf::Window &window) {

  int pivot = arr[high];
  int i = low;

  for (int j = i; j < high; j++) {
    if (arr[j] < pivot) {
      std::swap(arr[i], arr[j]);
      i = i + 1;
      render(arr, window, "Quick Sort");
    }
  }
  std::swap(arr[i], arr[high]);

  render(arr, window, "Quick Sort");

  return i;
}

void quickSort(std::vector<int> &arr, int low, int high, sf::Window &window) {
  if (low >= high)
    return;

  int pivotIndex = partition(arr, low, high, window);

  quickSort(arr, low, pivotIndex - 1, window);
  quickSort(arr, pivotIndex + 1, high, window);
}

void quickSort(std::vector<int> &arr, sf::Window &window) {
  if (arr.size() < 1)
    return;
  quickSort(arr, 0, arr.size() - 1, window);
}
