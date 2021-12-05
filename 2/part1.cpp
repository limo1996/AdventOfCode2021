#include <iostream>
#include <string>

using namespace std;

int main() {
  string command;
  int X, horizontal = 0, depth = 0;

  while(cin >> command >> X) {
    if (command == "forward") {
      horizontal += X;
    } else if (command == "down") {
      depth += X;
    } else {
      depth -= X;
    }
  }
  cout << horizontal * depth << endl;
  return 0;
}