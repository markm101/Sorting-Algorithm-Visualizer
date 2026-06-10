#include <iostream>
#include <utility>
#include <vector>

void BubbleSort(std::vector<int> &arr) {

  bool has_Swap = true;
  while (has_Swap == true) {
    has_Swap = false;
    for (int i = 0; i < (int(arr.size()) - 1); i++) {
      if (arr[i] > arr[i + 1]) {
        std::swap(arr[i], arr[i + 1]);
        has_Swap = true;
      }
    }
  }
}

int main() {
  std::vector<int> arr = {64, 25, 12, 22, 11, 45, 78, 33, 90, 15};

  BubbleSort(arr);

  for (int i : arr) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
