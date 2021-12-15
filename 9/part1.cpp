#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
  vector<vector<int>> heightMap;
  string line;
  while(getline(cin, line)) {
    vector<int> row(line.size());
    for(int i = 0; i < line.size(); i++)
      row[i] = line[i] - '0';
    heightMap.push_back(row);
  }
  int sum = 0;
  for (int i = 0; i < heightMap.size(); i++) {
    for (int j = 0; j < heightMap[i].size(); j++) {
      if ((i == 0 || heightMap[i-1][j] > heightMap[i][j]) &&
          (j == 0 || heightMap[i][j-1] > heightMap[i][j]) &&
          (i + 1 == heightMap.size() || heightMap[i+1][j] > heightMap[i][j]) &&
          (j + 1 == heightMap[i].size() || heightMap[i][j+1] > heightMap[i][j])) {
            sum += heightMap[i][j] + 1;
          }
    }
  }
  cout << sum << endl;
}