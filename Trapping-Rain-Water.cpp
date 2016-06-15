#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(vector<int> &nums) {
    if (nums.size() < 3)
      return 0;
    int water = 0;
    int max = 0;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] > nums[max])
        max = i;
    int leftmax = nums[0];
    int rightmax = nums[nums.size() - 1];
    for (int i = 1; i < max; i++) {
      if (nums[i] < leftmax)
        water += leftmax - nums[i];
      else
        leftmax = nums[i];
    }
    for (int i = nums.size() - 2; i > max; i--) {
      if (nums[i] < rightmax)
        water += rightmax - nums[i];
      else
        rightmax = nums[i];
    }
    return water;
  }
};

int main() {
  vector<int> nums{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  Solution s;
  cout << s.trap(nums) << endl;
}
