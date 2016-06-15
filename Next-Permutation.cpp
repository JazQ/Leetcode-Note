#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &nums) {
    int s = nums.size() - 1;
    int temp = 0;
    for (int i = s; i > 0; i--) {
      if (nums[i] > nums[i - 1]) {
        for (int j = s; j >= i; j--) {
          if (nums[j] > nums[i - 1])
            swap(nums[j], nums[i - 1]);
        }
        temp = i;
        break;
      }
    }
    while (temp < s)
      swap(nums[temp++], nums[s--]);
  }
};

int main() {
  vector<int> nums{};
  Solution S;
  S.nextPermutation(nums);
  for (auto i : nums)
    cout << i << " ";
  cout << endl;
}
