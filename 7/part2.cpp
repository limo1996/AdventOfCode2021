#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <algorithm>

using namespace std;

vector<int> loadInitState() {
  string line;
  getline(cin, line);
  istringstream is(line);
  return vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
}

int main() {
  vector<int> initState = loadInitState();
  int max_pos = *std::max_element(initState.begin(), initState.end());
  int best_pos = INT_MAX;
  for (int i = 0; i <= max_pos; i++) {
    int sum = 0;
    for (int j = 0; j < initState.size(); j++) {
      int diff = abs(initState[j] - i);
      sum += diff * (1 + diff) / 2;
    }
    best_pos = min(best_pos, sum);
  }
  cout << best_pos << endl;
  return 0;
}