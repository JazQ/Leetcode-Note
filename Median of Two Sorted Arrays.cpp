#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
  {
    int n = nums1.size(), m = nums2.size();
    int t = n + m;
    if (t % 2 == 1)
      return findk(nums1.begin(), nums2.begin(), n, m, t / 2 + 1);
    else
      return (findk(nums1.begin(), nums2.begin(), n, m, t / 2) +
              findk(nums1.begin(), nums2.begin(), n, m, t / 2 + 1)) /
             2.0;
  }

private:
  double findk(vector<int>::iterator N, vector<int>::iterator M, int n, int m,
               int k)
  {
    if (n > m)
      return findk(M, N, m, n, k);
    if (n == 0)
      return *(M + k - 1);
    if (k == 1)
      return min(*N, *M);

    int a = min(k / 2, n), b = k - a;
    if (*(N + a - 1) < *(M + b - 1))
      return findk(N + a, M, n - a, m, k - a);
    else if (*(N + a - 1) > *(M + b - 1))
      return findk(N, M + b, n, m - b, k - b);
    else
      return *(N + a - 1);
  }
};

int
main()
{
  vector<int> nums1{};
  vector<int> nums2{ 1 };
  Solution S;
  cout << S.findMedianSortedArrays(nums1, nums2) << endl;

  system("pause");
  return 0;
}
