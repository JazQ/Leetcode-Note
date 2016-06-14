#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  vector<vector<int>> fourSum(vector<int>& nums, int target)
  {
    vector<vector<int>> result;
    if (nums.size() < 4)
      return result;
    sort(nums.begin(), nums.end());

    vector<int> v;
    for (int a = 0; a < nums.size() - 3; a++) {
      for (int b = a + 1; b < nums.size() - 2; b++) {
        int c = b + 1;
        int d = nums.size() - 1;
        while (c < d) {
          int sum = nums[a] + nums[b] + nums[c] + nums[d];
          if (sum < target) {
            c++;
          } else if (sum > target) {
            d--;
          } else {
            v.push_back(nums[a]);
            v.push_back(nums[b]);
            v.push_back(nums[c]);
            v.push_back(nums[d]);
            result.push_back(v);
            v.clear();
            c++;
            d--;
          }
        }
      }
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    return result;
  }
};

int
main()
{
  vector<int> nums;
  int a[] = { 1, 0, -1, 0, -2, 2 };
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    nums.push_back(a[i]);
  Solution S;
  vector<vector<int>> result;
  result = S.fourSum(nums, 0);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      cout << result[i][j] << " ";
    cout << endl;
  }
}
