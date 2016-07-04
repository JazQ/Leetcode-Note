#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<int> result;
    for (int i = 0; i <= rowIndex; i++) {
      for (int j = i - 1; j > 0; j--) {
        result[j] = result[j] + result[j - 1];
      }
      result.push_back(1);
    }
    return result;
  }
};
int main() {
  int numRows;
  cout << "行数：";
  cin >> numRows;
  Solution s;
  vector<int> result = s.getRow(numRows);
  for (auto i : result) cout << i << " ";
  cout << endl;
}
