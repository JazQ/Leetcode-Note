#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int climbStairs(int n) {
    int cur = 1, prev = 0;
    for (int i = 1; i <= n; i++) {
      int tmp = cur;
      cur += prev;
      prev = tmp;
    }
    return cur;
  }
};

int main() {
  Solution s;
  cout << s.climbStairs(7) << endl;
}
