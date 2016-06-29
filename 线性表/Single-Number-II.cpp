#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int singleNumber(vector<int> &nums) {
    vector<int> bit(32);
    int result = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = 0; j < 32; j++) {
        bit[j] += (nums[i] >> j) & 1;
        bit[j] %= 3;
      }
    }
    for (int i = 0; i < 32; i++)
      result += bit[i] << i;
    return result;
  }
};

int main() {
  vector<int> nums{1, 1, 1, 2, 2, 2, 3, 4, 4, 4};
  Solution s;
  cout << s.singleNumber(nums) << endl;
}
