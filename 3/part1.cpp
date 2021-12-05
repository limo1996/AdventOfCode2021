#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int binToInt(vector<int> bin) {
  int result = 0;
  for (int i = 0; i < 12; i++) {
    result += bin[i] * pow(2, 11-i);
  }
  return result;
}

int main() {
  vector<vector<int> > counter(2, vector<int>(12, 0));
  string line;
  while(cin >> line) {
    for (int i = 0; i < 12; i++) {
      counter[line[i]-'0'][i]++;
    }
  }

  vector<int> gamma(12, 0);
  vector<int> epsilon(12, 0);

  for (int i = 0; i < 12; i++) {
    if(counter[0][i] > counter[1][i]){
      gamma[i] = 0;
      epsilon[i] = 1;
    } else {
      gamma[i] = 1;
      epsilon[i] = 0;
    }
  }

  cout << binToInt(gamma) * binToInt(epsilon) << endl;
  return 0;
}