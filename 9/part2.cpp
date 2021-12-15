#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

int bfs(int x, int y, int X, int Y, vector<vector<int>> &heightMap, vector<vector<bool>> &visited) {
  int sum = 0;
  queue<pair<int,int>> q;
  q.push(make_pair(x, y));
  while(!q.empty()) {
    int i = q.front().first;
    int j = q.front().second;
    q.pop();

    if (i < 0 || j < 0 || i >= X || j >= Y)
      continue;
    if (visited[i][j])
      continue;
    if (heightMap[i][j] == 9)
      continue;

    visited[i][j] = true;
    sum++;
    q.push(make_pair(i - 1, j));
    q.push(make_pair(i, j - 1));
    q.push(make_pair(i + 1, j));
    q.push(make_pair(i, j + 1));
  }
  return sum;
}

int main() {
  vector<vector<int>> heightMap;
  string line;
  while(getline(cin, line)) {
    vector<int> row(line.size());
    for(int i = 0; i < line.size(); i++)
      row[i] = line[i] - '0';
    heightMap.push_back(row);
  }

  int X = heightMap.size(), Y = heightMap[0].size();
  vector<vector<bool>> visited(X, vector<bool>(Y, false));
  vector<int> sums;
  for (int i = 0; i < X; i++) {
    for (int j = 0; j < Y; j++) {
      if (!visited[i][j] && heightMap[i][j] != 9) {
        sums.push_back(bfs(i, j, X, Y, heightMap, visited));
      }
    }
  }

  sort(sums.begin(), sums.end(), greater<int>());
  cout << sums[0] * sums[1] * sums[2] << endl;
}