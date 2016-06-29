#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.size(); i++)
      if (nums[i] != val)
        nums[index++] = nums[i];
    return index;
  }
};

int main() {
  vector<int> nums{3, 2, 2, 3};
  Solution S;
  cout << S.removeElement(nums, 3) << endl;
}
