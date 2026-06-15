#include "sorting/mergesort.h"

#include "visuals/visualizer.h"

void inner_merge(std::vector<int> &arr, int left, int right,
                 sf::RenderWindow &window) {

  int middle = left + (right - left) / 2;

  std::vector<int> temp;

  int i = left;
  int j = middle + 1;

  while (i <= middle && j <= right) {
    if (arr[i] <= arr[j]) {
      temp.push_back(arr[i]);
      i += 1;
    } else {
      temp.push_back(arr[j]);
      j += 1;
    }
  }

  while (i <= middle) {
    temp.push_back(arr[i]);
    i++;
  }
  while (j <= right) {
    temp.push_back(arr[j]);
    j++;
  }

  for (int k = 0; k < int(temp.size()) && window.isOpen(); k++) {
    arr[k + left] = temp[k];

    sf::sleep(sf::milliseconds(80));
    render(arr, window, "Merge Sort");
  }
}

void outer_merge(std::vector<int> &arr, int left, int right,
                 sf::RenderWindow &window) {
  if (left >= right || !window.isOpen()) {
    return;
  }

  int mid = left + (right - left) / 2;

  outer_merge(arr, left, mid, window);
  outer_merge(arr, mid + 1, right, window);
  inner_merge(arr, left, right, window);
}

void MergeSort(std::vector<int> &arr, sf::RenderWindow &window) {
  if (arr.empty()) {
    return;
  }

  outer_merge(arr, 0, int(arr.size()) - 1, window);
}
