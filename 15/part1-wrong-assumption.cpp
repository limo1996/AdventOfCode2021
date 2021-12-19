#include <iostream>
#include <vector>
#include <string>

using namespace std;
/* This is not working because I somehow though one can move only down or to the right :( */

vector<vector<int>> loadGrid() {
  string line;
  vector<vector<int>> grid;
  while (getline(cin, line)) {
    vector<int> l;
    for (int i = 0; i < line.size(); i++)
      l.push_back(line[i] - '0');
    grid.push_back(l);
  }
  return grid;
}

int main() {
  auto grid = loadGrid();
  int X = grid.size(), Y = grid[0].size();
  vector<vector<int>> DP(X, vector<int>(Y, 0));
  DP[X-1][Y-1] = grid[X-1][Y-1];
  for (int i = Y - 2; i >= 0; i--)
    DP[X-1][i] = DP[X-1][i+1] + grid[X-1][i+1];
  for (int i = X - 2; i >= 0; i--)
    DP[i][Y-1] = DP[i+1][Y-1] + grid[i+1][Y-1];
  for (int k = Y - 1; k > 1; k--) {
    int j = k-1, i = X - 2;
    for (; j < Y - 1; j++,i--) {
      if (DP[i+1][j] < DP[i][j+1])
        DP[i][j] = grid[i][j] + DP[i+1][j];
      else
        DP[i][j] = grid[i][j] + DP[i][j+1];
    }
  }
  for (int k = X - 2; k >= 0; k--) {
    int i = 0, j = k;
    for (; j >= 0; j--,i++) {
      if (DP[i+1][j] < DP[i][j+1])
        DP[i][j] = grid[i][j] + DP[i+1][j];
      else
        DP[i][j] = grid[i][j] + DP[i][j+1];
    }
  }
  cout << DP[0][0] << endl;
  return 0;
}