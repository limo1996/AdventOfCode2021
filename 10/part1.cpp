#include <string>
#include <map>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int main() {
  int score = 0;
  string line;
  map<char, int> scores;
  map<char, char> brackets;
  map<char, bool> open;
  scores[')'] = 3;      brackets[')'] = '(';  open[')'] = false;  open['('] = true;
  scores[']'] = 57;     brackets[']'] = '[';  open[']'] = false;  open['['] = true;
  scores['}'] = 1197;   brackets['}'] = '{';  open['}'] = false;  open['{'] = true;
  scores['>'] = 25137;  brackets['>'] = '<';  open['>'] = false;  open['<'] = true;
  while (getline(cin, line)) {
    stack<char> s;
    for (int i = 0; i < line.size(); i++) {
      if (open[line[i]]) {
        s.push(line[i]);
      } else {
        if (brackets[line[i]] != s.top()) {
          score += scores[line[i]];
          break;
        }
        s.pop();
      }
    }
  }
  cout << score << endl;
  return 0;
}