#include <iostream>
#include <vector>
#include <sstream>
#include <iterator>

using namespace std;

bool loadBoard(vector<vector<int>> &boards, vector<vector<bool>> &marks) {
  vector<int> board;
  vector<bool> mark(25, false);
  int i = 0;
  string line;
  getline(cin, line);
  for (int i = 0; i < 25; i+=5) {
    if (!getline(cin, line))
      return false;
    istringstream is(line);
    board.insert(board.end(), std::istream_iterator<int>(is),
                              std::istream_iterator<int>() );
  }
  boards.push_back(board);
  marks.push_back(mark);
  return true;
}

vector<int> loadOrder() {
  string s, in;
  getline(cin, in);
  istringstream ss(in);
  vector<int> order;
  while (getline(ss, s, ',')) {
    order.push_back(std::stoi(s));
  }
  return order;
}

int solve(vector<int> &order, vector<vector<int>> &boards, vector<vector<bool>> &marks) {
  vector<bool> winners(boards.size(), false);
  int wins = 0;

  for (int i = 0; i < order.size(); i++) {
    int curr = order[i];

    for (int j = 0; j < boards.size(); j++) {
      if (winners[j]) // this board has already won
        continue;
      for (int k = 0; k < 25; k++) {
        if (boards[j][k] == curr) {
          marks[j][k] = true;
          int row = k / 5;
          int column = k % 5;
          bool allRow = true, allColumn = true;
          // check row
          for (int r = 0; r < 5; r++)
            allRow = allRow && marks[j][row*5+r];
          for (int c = 0; c < 5; c++)
            allColumn = allColumn && marks[j][c*5+column];
          if (allRow || allColumn) {
            winners[j] = true;

            // this is the last one
            if (wins == boards.size() - 1) {
              int sum = 0;
              for (int ii = 0; ii < 25; ii++) {
                if (!marks[j][ii])
                  sum += boards[j][ii];
              }
              return sum * curr;
            }
            wins++;
            break;
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  vector<int> order = loadOrder();
  vector<vector<int>> boards;
  vector<vector<bool>> marks;
  while(loadBoard(boards, marks)) ;

  cout << solve(order, boards, marks) << endl;

  return 0;
}