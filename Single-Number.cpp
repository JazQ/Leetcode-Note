#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    int x = 0;
    for (auto i : nums)
      x ^= i;
    return x;
  }
};

int main() {
  vector<int> nums{1, 1, 2, 2, 3, 4, 4};
  Solution s;
  cout << s.singleNumber(nums) << endl;
  ;
}
