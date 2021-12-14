#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main() {
  int j = 0;
  vector<string> s(15, "");
  while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7] >> s[8] >> s[9] >> s[10] >> s[11] >> s[12] >> s[13] >> s[14]) {
    for (int i = 10; i < 15; i++)
      if (s[i].size() == 2 || s[i].size() == 3 || s[i].size() == 4 || s[i].size() == 7)
        j++;
  }
  cout << j << endl;
}