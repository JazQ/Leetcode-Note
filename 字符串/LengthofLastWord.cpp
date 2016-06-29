#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
    for (int i = s.size() - 1; i >= 0; i--) {
      if (s[i] != ' ') {
        s = s.substr(0, i + 1);
        break;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ' ') {
        s = s.substr(i + 1, s.size());
        i = -1;
      }
    }
    return s.size();
  }
};

int main() {
  string s("a ");
  Solution sl;
  int a = sl.lengthOfLastWord(s);
  cout << a << endl;
}
