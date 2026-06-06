#include "sorting/selectionsort.h"

void selectionSort(std::vector<int> &arr) {

  for (int i = 0; i < int(arr.size()); i++) {
    int minindex = i;
    for (int p = i + 1; p < int(arr.size()); p++) {
      if (arr[minindex] > arr[p]) {
        minindex = p;
      }
    }
    std::swap(arr[i], arr[minindex]);
  }
}
