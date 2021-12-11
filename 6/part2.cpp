#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>
#include <numeric>

using namespace std;

vector<uint64_t> loadInitState() {
  string line;
  getline(cin, line);
  istringstream is(line);
  auto v = vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
  vector<uint64_t> initState(9, 0);
  for (auto i : v)
    initState[i]++;
  return initState;
}

int main() {
  vector<uint64_t> initState = loadInitState();

  for (int i = 0; i < 256; i++) {
    uint64_t tmp0 = initState[0];

    for (int i = 0; i < 8; i++)
      initState[i] = initState[i+1];

    initState[6] += tmp0;
    initState[8] = tmp0;
  }

  cout << accumulate(initState.begin(), initState.end(), 0ull) << endl;

  return 0;
}