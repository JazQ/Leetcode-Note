#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int sum = 0;
    int total = 0;
    int j = -1;
    for (int i = 0; i < gas.size(); i++) {
      sum += gas[i] - cost[i];
      total += gas[i] - cost[i];
      if (sum < 0) {
        j = i;
        sum = 0;
      }
    }
    return total < 0 ? -1 : j + 1;
  }
};

int main() {
  vector<int> gas{4};
  vector<int> cost{5};
  Solution s;
  cout << s.canCompleteCircuit(gas, cost) << endl;
}
