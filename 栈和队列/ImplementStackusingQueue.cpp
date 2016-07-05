#include <iostream>
#include <queue>

using namespace std;

class Stack {
 public:
  // Push element x onto stack.
  void push(int x) {
    if (queue2.empty())
      queue1.push(x);
    else
      queue2.push(x);
  }

  // Removes the element on top of the stack.
  void pop() {
    if (queue2.empty()) {
      while (queue1.size() != 1) {
        queue2.push(queue1.front());
        queue1.pop();
      }
      queue1.pop();
    } else {
      while (queue2.size() != 1) {
        queue1.push(queue2.front());
        queue2.pop();
      }
      queue2.pop();
    }
  }

  // Get the top element.
  int top() {
    if (queue2.empty()) {
      while (queue1.size() != 1) {
        queue2.push(queue1.front());
        queue1.pop();
      }
      int a = queue1.front();
      queue2.push(a);
      queue1.pop();
      return a;
    } else {
      while (queue2.size() != 1) {
        queue1.push(queue2.front());
        queue2.pop();
      }
      int a = queue2.front();
      queue1.push(a);
      queue2.pop();
      return a;
    }
  }

  // Return whether the stack is empty.
  bool empty() { return queue1.empty() && queue2.empty(); }

 private:
  queue<int> queue1;
  queue<int> queue2;
};
