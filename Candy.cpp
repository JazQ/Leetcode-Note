#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int N = ratings.size();
    vector<int> give(N);
    int result = N;
    //与左边数字进行比较
    for (int i = 1, inc = 1; i < N; i++) {
      if (ratings[i] > ratings[i - 1])
        give[i] = max(++inc, give[i]);
      else {
        inc = 1;
        give[i] = 1;
      }
    }
    //与右边数字比较
    for (int i = N - 2, inc = 1; i >= 0; i--) {
      if (ratings[i] > ratings[i + 1])
        give[i] = max(++inc, give[i]);
      else {
        inc = 1;
        give[i] = 1;
      }
    }
    for (auto i : give)
      result += i;
    return result;
  }
};

int main() {
  vector<int> ratings{0};
  Solution s;
  cout << s.candy(ratings) << endl;
}
