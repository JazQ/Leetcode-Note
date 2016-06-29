#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string addBinary(string a, string b) {
    int max = a.size() > b.size() ? a.size() : b.size();
    string c;
    int carry = 0;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    for (int i = 0; i < max; i++) {
      int ai = i < a.size() ? a[i] - '0' : 0;
      int bi = i < b.size() ? b[i] - '0' : 0;
      int sum = ai + bi + carry;
      carry = sum / 2;
      sum = sum % 2;
      c.insert(c.begin(), sum + '0');
    }
    if (carry == 1)
      c.insert(c.begin(), '1');
    return c;
  }
};

int main() {
  string a("11"), b("1");
  Solution s;
  string c = s.addBinary(a, b);
  cout << c << endl;
}
