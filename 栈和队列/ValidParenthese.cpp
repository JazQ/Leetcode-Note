#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    string left("([{");
    string right(")]}");
    stack<char> par;

    for (auto c : s) {
      if (left.find(c) != string::npos)
        par.push(c);
      else if (par.empty() || par.top() != left[right.find(c)])
        return false;
      else
        par.pop();
    }
    return par.empty();
  }
};

int main() {
  string s("]");
  Solution ss;
  bool res = ss.isValid(s);
  if (res)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
