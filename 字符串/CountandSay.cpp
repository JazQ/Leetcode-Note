#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string countAndSay(int n) {
    if (n == 1)
      return "1";
    string s("1");
    string next;
    for (int i = 0; i < n - 1; i++) {
      int len = s.size();
      int count = 1;
      for (int j = 0; j < len; j++) {
        while (s[j + 1] && s[j] == s[j + 1]) {
          count++;
          j++;
        }
        next.insert(next.end(), (count + '0'));
        next.insert(next.end(), s[j]);
        count = 1;
      }
      s = next;
      next = "";
    }
    return s;
  }
};

int main() {
  Solution s;
  string result = s.countAndSay(6);
  cout << result << endl;
}
