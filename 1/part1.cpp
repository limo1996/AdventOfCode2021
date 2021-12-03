#include <iostream>

int main() {
  int prev, curr, result = 0;
  std::cin >> prev;
  while(std::cin >> curr) {
    if (curr > prev) result++;
    prev = curr;
  }
  std::cout << result << std::endl;
  return 0;
}