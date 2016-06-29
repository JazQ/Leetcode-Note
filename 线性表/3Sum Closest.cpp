#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &nums, int target) {
    vector<int>::const_iterator last = nums.end();
    int sum = 0;
    int clo = INT_MAX;
    sort(nums.begin(), nums.end());
    for (vector<int>::const_iterator i = nums.begin(); i < last - 2; ++i) {
      vector<int>::const_iterator j = i + 1;
      vector<int>::const_iterator k = last - 1;
      while (j < k) {
        int tdis = abs(*i + *j + *k - target);
        if (tdis < clo) {
          sum = *i + *j + *k;
          clo = tdis;
        }
        if (*i + *j + *k < target)
          ++j;
        else
          --k;
      }
    }
    return sum;
  }
};

int main() {
  vector<int> nums;
  int a[] = {1, 2, 4, 8, 16, 32, 64, 128};
  for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++)
    nums.push_back(a[i]);
  Solution S;
  int sum = S.threeSumClosest(nums, 82);
  cout << sum << endl;
}
