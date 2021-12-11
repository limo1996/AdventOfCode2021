#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

vector<int> loadInitState() {
  string line;
  getline(cin, line);
  istringstream is(line);
  return vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
}

int main() {
  vector<int> initState = loadInitState();

  for (int i = 0; i < 80; i++) {
    int extra = 0;
    for (int j = 0; j < initState.size(); j++) {
      if (initState[j] == 0) {
        initState[j] = 6;
        extra++;
      } else
        initState[j]--;
    }
    for (int j = 0; j < extra; j++)
      initState.push_back(8);
  }

  cout << initState.size() << endl;

  return 0;
}