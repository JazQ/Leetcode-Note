#include <cmath>
#include <iostream>

using namespace std;

class Solution {
 public:
  int reverse(int x) {
    bool zf = x > 0 ? true : false;
    long long t = x;
    if (!zf) t = -t;
    long int r = 0;
    for (; t; t /= 10) r = t % 10 + r * 10;
    if (r > 2147483647 || (!zf && r > 2147483648))
      return 0;
    else {
      if (zf)
        return r;
      else
        return -r;
    }
  }
};

int main() {
  int x = -2147483648;
  Solution s;
  x = s.reverse(x);
  cout << x << endl;
}
