#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<vector<char>> loadGrid(int &X, int &Y) {
  vector<pair<int,int>> input;
  int x, y;
  X = 0, Y = 0;
  while (cin >> x >> y) {
    input.push_back(make_pair(y,x));
    X = max(x, X);
    Y = max(y, Y);
  }
  vector<vector<char>> grid(++Y, vector<char>(++X, '.'));
  for (auto p : input)
    grid[p.first][p.second] = '#';

  return grid;
}

void foldX(vector<vector<char>> &grid, int X, int Y, int foldAlongX) {
  for (int y = 0; y < Y; y++) {
    for (int x = foldAlongX; x < X; x++) {
      if (grid[y][x] == '#') {
        grid[y][2*foldAlongX - x] = '#';
      }
    }
  }
}

int main() {
  int X, Y;
  vector<vector<char>> grid = loadGrid(X, Y);
  int foldAlongX = 655;
  
  foldX(grid, X, Y, foldAlongX);

  int dots = 0;
  for (int y = 0; y < Y; y++) {
    for (int x = 0; x < foldAlongX; x++) {
      if (grid[y][x] == '#')
        dots++;
    }
  }
  cout << dots << endl;
}