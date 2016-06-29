#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode *CreateList() {
  int a;
  cin >> a;
  if (a >= 0) {
    ListNode *head = new ListNode(a);
    head->next = CreateList();
    return head;
  }
  return NULL;
}

class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode dummy(-1);
    dummy.next = head;
    ListNode *shead = &dummy;

    while (shead->next != NULL && shead->next->val < x)
      shead = shead->next;
    if (shead->next == NULL)
      return dummy.next;
    ListNode *prev = shead->next;
    while (prev->next != NULL) {
      while (prev->next != NULL && prev->next->val >= x)
        prev = prev->next;
      if (prev->next == NULL)
        return dummy.next;
      ListNode *cur = prev->next;
      prev->next = cur->next;
      cur->next = shead->next;
      shead->next = cur;
      shead = cur;
      cur = prev->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  head = s.partition(head, 3);
  for (; head != NULL; head = head->next)
    cout << head->val << "->";
  cout << "NULL" << endl;
}
