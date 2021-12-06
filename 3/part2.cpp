#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int binToInt(string bin) {
  int result = 0;
  for (int i = 0; i < 12; i++) {
    result += (bin[i] - '0') * pow(2, 11-i);
  }
  return result;
}

vector<vector<int> > count(vector<string> lines) {
  vector<vector<int> > counter(2, vector<int>(12, 0));
  for (string line : lines) {
    for (int i = 0; i < 12; i++) {
      counter[line[i]-'0'][i]++;
    }
  }
  return counter;
}

int main() {
  vector<vector<int> > counter;
  string line;
  vector<string> lines;
  while(cin >> line) {
    lines.push_back(line);
  }

  vector<string> oxygen(lines.begin(), lines.end());
  vector<string> CO2(lines.begin(), lines.end());

  for (int i = 0; i < 12; i++) {
    vector<string> tmpOxygen;
    counter = count(oxygen);
    for (int j = 0; j < oxygen.size(); j++) {
      if (counter[1][i] >= counter[0][i] && oxygen[j][i] == '1')
        tmpOxygen.push_back(oxygen[j]);
      else if (counter[0][i] > counter[1][i] && oxygen[j][i] == '0')
        tmpOxygen.push_back(oxygen[j]);
    }
    oxygen.clear();
    oxygen = vector<string>(tmpOxygen.begin(), tmpOxygen.end());
    if (oxygen.size() == 1)
      break;
  }
  
  for (int i = 0; i < 12; i++) {
    vector<string> tmpCO2;
    counter = count(CO2);
    for (int j = 0; j < CO2.size(); j++) {
      if (counter[0][i] <= counter[1][i] && CO2[j][i] == '0')
        tmpCO2.push_back(CO2[j]);
      else if (counter[1][i] < counter[0][i] && CO2[j][i] == '1')
        tmpCO2.push_back(CO2[j]);
    }
    CO2.clear();
    CO2 = vector<string>(tmpCO2.begin(), tmpCO2.end());
    if (CO2.size() == 1)
      break;
  }

  assert(oxygen.size() == 1);
  assert(CO2.size() == 1);

  cout << binToInt(oxygen[0]) * binToInt(CO2[0]) << endl;
  return 0;
}