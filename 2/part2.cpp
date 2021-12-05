#include <iostream>
#include <string>

using namespace std;

int main() {
  string command;
  int X, horizontal = 0, depth = 0, aim = 0;

  while(cin >> command >> X) {
    if (command == "forward") {
      horizontal += X;
      depth += X * aim;
    } else if (command == "down") {
      aim += X;
    } else {
      aim -= X;
    }
  }
  cout << horizontal * depth << endl;
  return 0;
}