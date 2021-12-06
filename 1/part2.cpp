#include <iostream>

int main() {
  int prev[3];
  int curr[3];
  int result = 0, i = 2;
  std::cin >> prev[0] >> prev[1] >> prev[2];
  curr[0] = prev[1];
  curr[1] = prev[2];
  while(std::cin >> curr[i % 3]) {
    if (curr[2] + curr[1] + curr[0] > prev[2] + prev[1] + prev[0]) result++;
    prev[(i - 2) % 3] = curr[i % 3];
    i++;
  }
  std::cout << result << std::endl;
  return 0;
}