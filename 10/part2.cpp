#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
  vector<uint64_t> result;
  string line;
  map<char, int> scores;
  map<char, char> brackets;
  map<char, bool> open;
  scores[')'] = 1;  brackets['('] = ')';  open[')'] = false;  open['('] = true;
  scores[']'] = 2;  brackets['['] = ']';  open[']'] = false;  open['['] = true;
  scores['}'] = 3;  brackets['{'] = '}';  open['}'] = false;  open['{'] = true;
  scores['>'] = 4;  brackets['<'] = '>';  open['>'] = false;  open['<'] = true;
  while (getline(cin, line)) {
    stack<char> s;
    bool cancel = false;
    for (int i = 0; i < line.size(); i++) {
      if (open[line[i]]) {
        s.push(line[i]);
      } else {
        if (brackets[s.top()] != line[i]) {
          cancel = true;
          break;
        }
        s.pop();
      }
    }
    if(cancel)
      continue;
    uint64_t score = 0;
    while (!s.empty()) {
      score *= 5;
      score += scores[brackets[s.top()]];
      s.pop();
    }
    result.push_back(score);
  }
  sort(result.begin(), result.end());
  cout << result[result.size()/2] << endl;
  return 0;
}