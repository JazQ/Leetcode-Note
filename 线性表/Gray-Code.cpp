#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> grayCode(int n) {
    vector<int> result;
    result.reserve(1 << n);
    result.push_back(0);
    for (int i = 0; i < n; i++) {
      int addnum = 1 << i;
      for (int j = result.size() - 1; j >= 0; j--)
        result.push_back(addnum | result[j]);
    }
    return result;
  }
};

int main() {
  vector<int> result;
  Solution s;
  result = s.grayCode(3);
  for (auto i : result)
    cout << i << " ";
  cout << endl;
}
