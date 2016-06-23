#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *CreateList() {
  int a;
  cin >> a;
  while (a >= 0) {
    ListNode *head = new ListNode(a);
    head->next = CreateList();
    return head;
  }
  return NULL;
}

class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    while (head && head->next) {
      ListNode dummy(-1);
      dummy.next = head;
      ListNode *prev = &dummy;
      ListNode *first = head;
      ListNode *second = head->next;
      prev->next = second;
      first->next = second->next;
      second->next = first;
      first->next = swapPairs(first->next);
      return dummy.next;
    }
    return head;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  head = s.swapPairs(head);
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}
