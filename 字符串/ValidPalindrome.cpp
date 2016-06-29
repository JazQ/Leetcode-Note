#include <algorithm>
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool isPalindrome(string s) {
    transform(s.begin(), s.end(), s.begin(), ::tolower);
    auto left = s.begin(), right = s.end();
    while (left < right) {
      if (!isalpha(*left))
        left++;
      else if (!isalpha(*right))
        right--;
      else if (*left != *right)
        return false;
      else {
        left++;
        right--;
      }
    }
    return true;
  }
};

int main() {
  string s("A man, a plan, a canal: Panama");
  Solution so;
  if (so.isPalindrome(s))
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
