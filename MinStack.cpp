#include <iostrearm>
#include <stack>

using namespace std;

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {
    mainstack;
    minstack;
  }

  void push(int x) {
    mainstack.push(x);
    if (!minstack.empty()) {
      minstack.push(x < minstack.top() ? x : minstack.top());
    } else
      minstack.push(x);
  }

  void pop() {
    mainstack.pop();
    minstack.pop();
  }

  int top() { return mainstack.top(); }

  int getMin() { return minstack.top(); }

 private:
  stack<int> mainstack;
  stack<int> minstack;
};
