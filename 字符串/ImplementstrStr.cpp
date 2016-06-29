#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.empty())
      return 0;
    const int N = haystack.size() - needle.size() + 1;
    for (int i = 0; i < N; i++) {
      int j = i, k = 0;
      while (k < needle.size() && haystack[j] == needle[k]) {
        j++;
        k++;
      }
      if (k == needle.size())
        return i;
    }
    return -1;
  }
};

int main() {
  string haystack("This is a value!"), needle(" ");
  Solution s;
  int i = s.strStr(haystack, needle);
  cout << i << endl;
}
