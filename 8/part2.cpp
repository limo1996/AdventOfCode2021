#include <map>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int sum = 0;
  vector<string> s(10, "");
  string delimiter, a, b, c, d;
  while (cin >> s[0] >> s[1] >> s[2] >> s[3] >> s[4] >> s[5] >> s[6] >> s[7] >> s[8] >> s[9] >> delimiter >> a >> b >> c >> d) {
    sort(s.begin(), s.end(), []
    (const string& first, const string& second){
        return first.size() < second.size();
    });

    for (int i = 0; i < 10; i++)
      sort(s[i].begin(), s[i].end());

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(c.begin(), c.end());
    sort(d.begin(), d.end());

    map<string, int> nums;
    nums[s[0]] = 1;
    nums[s[1]] = 7;
    nums[s[2]] = 4;
    nums[s[9]] = 8;

    int zero, three, five, nine; 

    for (int i = 3; i <= 5; i++) {
      if (s[i].find(s[0][0]) != string::npos && s[i].find(s[0][1]) != string::npos) {
        nums[s[i]] = 3;
        three = i;
      }
    }

    for (int i = 6; i <= 8; i++) {
      if (s[i].find(s[2][0]) != string::npos && s[i].find(s[2][1]) != string::npos && s[i].find(s[2][2]) != string::npos && s[i].find(s[2][3]) != string::npos) {
        nums[s[i]] = 9;
        nine = i;
        continue;
      }
      if (s[i].find(s[0][0]) != string::npos && s[i].find(s[0][1]) != string::npos) {
        nums[s[i]] = 0;
        zero = i;
      }
    }

    for (int i = 3; i <= 5; i++) {
      if (i != three && s[nine].find(s[i][0]) != string::npos && s[nine].find(s[i][1]) != string::npos && s[nine].find(s[i][2]) != string::npos && s[nine].find(s[i][3]) != string::npos && s[nine].find(s[i][4]) != string::npos) {
        nums[s[i]] = 5;
        five = i;
      }
    }

    nums[s[6+7+8-zero-nine]] = 6;
    nums[s[3+4+5-three-five]] = 2;

    sum += nums[a] * 1000 + nums[b] * 100 + nums[c] * 10 + nums[d];
  }
  cout << sum << endl;
}