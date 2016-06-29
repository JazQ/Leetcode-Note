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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *first = &dummy;
    ListNode *last = &dummy;
    for (int i = 0; i < n; i++)
      first = first->next;
    while (first->next) {
      first = first->next;
      last = last->next;
    }
    last->next = last->next->next;
    return dummy.next;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  head = s.removeNthFromEnd(head, 2);
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}
