#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  int myAtoi(string str) {
    int num = 0, sign = 1, i = 0;
    int N = str.size();
    while (str[i] == ' ' && i < N)
      i++;
    if (str[i] == '+')
      i++;
    else if (str[i] == '-') {
      sign = -1;
      i++;
    }
    for (; i < N; i++) {
      if (str[i] < '0' || str[i] > '9')
        break;
      if (num > INT_MAX / 10 ||
          (num == INT_MAX / 10 && str[i] - '0' > INT_MAX % 10)) {
        if (sign == 1)
          return INT_MAX;
        else
          return INT_MIN;
      }
      num = num * 10 + str[i] - '0';
    }
    return sign * num;
  }
};

int main() {
  string str("-2147483647");
  Solution s;
  int num = s.myAtoi(str);
  cout << num << endl;
}
