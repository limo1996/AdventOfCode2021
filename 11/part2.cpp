#include <iostream>
#include <vector>
#include <vector>

using namespace std;

vector<vector<int>> loadGrid() {
  vector<vector<int>> grid;
  string line;
  while (getline(cin, line)) {
    vector<int> l(line.size());
    for (int j = 0; j < line.size(); j++) {
      l[j] = line[j] - '0';
    }
    grid.push_back(l);
  }
  return grid;
}

void flash(vector<vector<int>> &grid, vector<vector<bool>> &flashed, int X, int Y, int i, int j) {
  for (int ii = -1; ii <= 1; ii++) {
    for (int jj = -1; jj <= 1; jj++) {
      int x = ii+i;
      int y = jj+j;
      if (ii == 0 && jj == 0)
        continue;
      if (x >= 0 && y >= 0 && x < X && y < Y) {
        grid[x][y]++;
        if (grid[x][y] > 9 && !flashed[x][y]) {
          flashed[x][y] = true;
          flash(grid, flashed, X, Y, x, y);
        }
      }
    }
  }
}

int main() {
  auto grid = loadGrid();
  int X = grid.size(), Y = grid[0].size();
  int step=0;
  while (true) {
    step++;
    vector<vector<bool>> flashed(X, vector<bool>(Y, false));
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < Y; j++) {
        grid[i][j]++;
        if (grid[i][j] > 9 && !flashed[i][j]) {
          flashed[i][j] = true;
          flash(grid, flashed, X, Y, i, j);
        }
      }
    }
    bool allFlashed = true;
    for (int i = 0; i < X; i++) {
      for (int j = 0; j < Y; j++) {
        allFlashed = allFlashed && flashed[i][j];
        if (grid[i][j] > 9) {
          grid[i][j] = 0;
        }
      }
    }
    if (allFlashed)
      break;
  }

  cout << step << endl;
  return 0;
}
