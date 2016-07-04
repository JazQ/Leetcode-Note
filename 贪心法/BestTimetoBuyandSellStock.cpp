#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int profit = 0;
    int cur_min = prices[0];
    for (int i = 1; i < prices.size(); i++) {
      profit = max(profit, prices[i] - cur_min);
      cur_min = min(cur_min, prices[i]);
    }
    return profit;
  }
};

int main() {
  vector<int> prices{7, 1, 5, 3, 6, 4};
  Solution s;
  int profit = s.maxProfit(prices);
  cout << profit << endl;
}
