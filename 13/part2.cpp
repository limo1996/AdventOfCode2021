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

void foldY(vector<vector<char>> &grid, int X, int Y, int foldAlongY) {
  for (int y = foldAlongY; y < Y; y++) {
    for (int x = 0; x < X; x++) {
      if (grid[y][x] == '#') {
        grid[2*foldAlongY - y][x] = '#';
      }
    }
  }
}

int main() {
  int X, Y;
  vector<vector<char>> grid = loadGrid(X, Y);
/*
fold along x=655
fold along y=447
fold along x=327
fold along y=223
fold along x=163
fold along y=111
fold along x=81
fold along y=55
fold along x=40
fold along y=27
fold along y=13
fold along y=6
*/

  foldX(grid, X, Y, 655); // new X = 655, Y = Y
  foldY(grid, 655, Y, 447);
  foldX(grid, 655, 447, 327);
  foldY(grid, 327, 447, 223);
  foldX(grid, 327, 223, 163);
  foldY(grid, 163, 223, 111);
  foldX(grid, 163, 111, 81);
  foldY(grid, 81, 111, 55);
  foldX(grid, 81, 55, 40);
  foldY(grid, 40, 55, 27);
  foldY(grid, 40, 27, 13);
  foldY(grid, 40, 13, 6);

  for (int y = 0; y < 6; y++) {
    for (int x = 0; x < 40; x++)
      cout << grid[y][x];
    cout << endl;
  }
  return 0;
}