#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    const int n = digits.size();
    for (int i = n - 1; i >= 0; i--) {
      if (digits[i] == 9)
        digits[i] = 0;
      else {
        digits[i] += 1;
        break;
      }
    }
    if (digits[0] == 0) {
      digits.insert(digits.begin(), 1);
      //   vector<int> a(n + 1);
      //   a[0] = 1;
      //   for (int i = 0; i < n; i++)
      //     a[i + 1] = digits[i];
      //   return a;
    }
    return digits;
  }
};

int main() {
  vector<int> digits{9, 9, 9, 9, 9};
  vector<int> a;
  Solution s;
  a = s.plusOne(digits);
  for (auto i : a)
    cout << i << " ";
  cout << endl;
}
