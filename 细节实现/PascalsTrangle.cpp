#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> result;
    if (numRows == 0) return result;
    result.push_back(vector<int>{1});
    for (int i = 1; i < numRows; i++) {
      result.push_back(vector<int>{1});
      for (int j = 1; j < i; j++) {
        result[i].push_back(result[i - 1][j] + result[i - 1][j - 1]);
      }
      result[i].push_back(1);
    }
    return result;
  }
};
int main() {
  int numRows;
  cout << "行数：";
  cin >> numRows;
  Solution s;
  vector<vector<int>> result = s.generate(numRows);
  for (auto i : result) {
    for (int k = 1; k < numRows; k++) cout << " ";
    for (auto j : i) cout << j << " ";
    numRows--;
    cout << endl;
  }
}
