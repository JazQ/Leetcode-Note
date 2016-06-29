#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(vector<vector<int>> &matrix) {
    int n = matrix[0].size();
    cout << n << endl;
    for (int j = 0; j < n; j++)
      for (int i = 0; i < n / 2; i++)
        swap(matrix[i][j], matrix[n - i - 1][j]);
    for (int i = 0; i < n; i++)
      for (int j = i + 1; j < n; j++)
        swap(matrix[i][j], matrix[j][i]);
  }
};

int main() {
  vector<vector<int>> matrix{{1, 2}, {3, 4}};
  const int n = matrix[0].size();
  Solution s;
  s.rotate(matrix);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++)
      cout << matrix[i][j];
    cout << endl;
  }
}
