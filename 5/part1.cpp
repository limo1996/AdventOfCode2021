#include <vector>
#include <sstream>
#include <cassert>
#include <iostream>
#include <iterator>

using namespace std;

bool loadLine(vector<vector<int>> &lines, int& x1, int& y1) {
  string l;
  getline(cin, l);
  istringstream is(l);
  vector<int> line = vector<int>(std::istream_iterator<int>(is), std::istream_iterator<int>());
  if (line.empty())
    return false;

  // in this part we consider only vertical or horizontal lines
  if (line[0] == line[2] || line[1] == line[3]) {
    x1 = max(max(x1, line[0]), line[2]);
    y1 = max(max(y1, line[1]), line[3]);
    lines.push_back(line);
  }
  return true;
}


int main() {
  int x1 = 0, y1 = 0, result = 0;
  vector<vector<int>> lines;
  while (loadLine(lines, x1, y1));
  vector<vector<int>> board(++x1, vector<int>(++y1, 0));

  for (auto line : lines) {
    if (line[0] == line[2]) {
      for (int i = min(line[1], line[3]); i <= max(line[1], line[3]); i++)
        board[line[0]][i]++;
    } else if (line[1] == line[3]) {
      for (int i = min(line[0], line[2]); i <= max(line[0], line[2]); i++)
        board[i][line[1]]++;
    } else {
      assert(false);
    }
  }

  for (int i = 0; i < x1; i++)
    for (int j = 0; j < y1; j++)
      if (board[i][j] > 1)
        result++;
  
  cout << result << endl;
  return 0;
}


