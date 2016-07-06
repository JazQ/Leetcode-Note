#include <iostream>

using namespace std;

class Solution {
 public:
  double myPow(double x, int n) {
    if (n < 0)
      return 1.0 / power(x, -n);
    else
      return power(x, n);
  }

 private:
  double power(double x, int n) {
    if (n == 0) return 1;
    double xhalf = power(x, n / 2);
    if (n % 2 == 0)
      return xhalf * xhalf;
    else
      return xhalf * xhalf * x;
  }
};

int main() {
  double x = 0.00000;
  Solution s;
  x = s.myPow(x, -11);
  cout << x << endl;
}
