#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string getPermutation(int n, int k) {
    string s;
    int a = 0;
    if (n == 1) {
      s.push_back('1');
      return s;
    }
    unordered_map<int, bool> v;
    for (int i = 1; i <= n; i++)
      v[i] = false;
    int k1 = (k - 1);
    while (n > 0) {
      int base = factorial(n - 1);
      int temp = k1 / base;
      a = finda(v, temp);
      s.push_back(a + '0');
      v[a] = true;
      k1 = k1 % base;
      n--;
    }
    cout << s << endl;
    return s;
  }

private:
  int factorial(int n) {
    int s = 1;
    for (int i = 1; i <= n; i++)
      s *= i;
    return s;
  }
  int finda(unordered_map<int, bool> v, int temp) {
    int m = 1;
    for (int i = 1; i <= temp; i++) {
      if (!v[m])
        m++;
      else {
        m++;
        i--;
      }
    }
    while (v[m])
      m++;
    return m;
  }
};

int main() {
  Solution S;
  S.getPermutation(5, 20);
}
