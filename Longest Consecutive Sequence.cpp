#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestConsecutive(vector<int> &nums) {
    unordered_map<int, bool> M;
    int Max = 0, thisnum = 0;
    for (int i = 0; i < nums.size(); i++)
      M[nums[i]] = false;
    for (int i = 0; i < nums.size(); i++) {
      thisnum = 0;
      for (int j = 0; M.find(nums[i] + j) != M.end() && !M[nums[i] + j]; j++) {
        M[nums[i] + j] = true;
        thisnum++;
      }
      for (int j = 1; M.find(nums[i] - j) != M.end() && !M[nums[i] - j]; j++) {
        M[nums[i] - j] = true;
        thisnum++;
      }
      Max = max(thisnum, Max);
    }
    return Max;
  }
};

int main() {
  vector<int> nums;
  int a[] = {100, 5, 4, 200, 1, 3, 2, 6};
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    nums.push_back(a[i]);
  Solution S;
  cout << S.longestConsecutive(nums) << endl;
}
