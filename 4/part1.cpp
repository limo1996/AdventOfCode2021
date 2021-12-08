#include <iostream>
#include <vector>

using namespace std;

bool loadBoard(vector<int*> &boards, vector<bool*> &marks) {
  int board[25];
  bool mark[25] = {false};
  for (int i = 0 ; i < 25; i++) {
    if (!cin >> board[i])
      return false;
  }
  boards.push_back(board);
  marks.push_back(mark);
  return true;
}

vector<int> loadOrder() {
  vector<int> order;
  int i;
  while (cin >> i) {
    order.push_back(i);
  }
  return order;
}

int solve(vector<int> &order, vector<int*> &boards, vector<bool*> &marks) {
  for (int i = 0; i < order.size(); i++) {
    int curr = order[i];

    for (int j = 0; j < boards.size(); j++) {
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
            int sum = 0;
            for (int ii = 0; ii < 25; ii++) {
              if (!marks[j][ii])
                sum += boards[j][ii];
            }
            return sum * curr;
          }
        }
      }
    }
  }
  return -1;
}

int main() {
  vector<int> order = loadOrder();
  vector<int*> boards;
  vector<bool*> marks;
  while(loadBoard(boards, marks)) ;

  cout << solve(order, boards, marks) << endl;

  return 0;
}