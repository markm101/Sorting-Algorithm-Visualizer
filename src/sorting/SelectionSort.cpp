#include <iostream>
#include <vector>

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

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11};

  selectionSort(arr);

  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
