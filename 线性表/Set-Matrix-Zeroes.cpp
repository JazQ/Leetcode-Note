#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void setZeroes(vector<vector<int>> &matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    bool rowb = false;
    bool colb = false;
    for (int i = 0; i < col; i++) {
      if (matrix[0][i] == 0) {
        rowb = true;
        break;
      }
    }
    for (int i = 0; i < row; i++) {
      if (matrix[i][0] == 0) {
        colb = true;
        break;
      }
    }
    for (int i = 1; i < row; i++) {
      for (int j = 1; j < col; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }
    for (int i = 1; i < col; i++) {
      if (matrix[0][i] == 0) {
        for (int j = 1; j < row; j++)
          matrix[j][i] = 0;
      }
    }
    for (int i = 1; i < row; i++) {
      if (matrix[i][0] == 0) {
        for (int j = 1; j < col; j++)
          matrix[i][j] = 0;
      }
    }
    if (rowb)
      for (int i = 0; i < col; i++)
        matrix[0][i] = 0;
    if (colb)
      for (int i = 0; i < row; i++)
        matrix[i][0] = 0;
  }
};

int main() {
  vector<vector<int>> matrix{
      {0, 0, 0, 5}, {4, 3, 1, 4}, {0, 1, 1, 4}, {1, 2, 1, 3}, {0, 0, 1, 1}};
  Solution s;
  s.setZeroes(matrix);
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = 0; j < matrix[0].size(); j++)
      cout << matrix[i][j] << " ";
    cout << endl;
  }
}
