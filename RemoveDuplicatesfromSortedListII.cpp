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
  ListNode *deleteDuplicates(ListNode *head) {
    if (head == NULL || head->next == NULL)
      return head;
    ListNode dummy(head->val + 1);
    dummy.next = head;
    ListNode *pre = &dummy;
    ListNode *beg = head;
    ListNode *cur = head->next;
    while (cur != NULL) {
      while (cur != NULL && beg->val != cur->val) {
        pre = pre->next;
        beg = beg->next;
        cur = cur->next;
      }
      if (cur == NULL)
        return dummy.next;
      while (cur != NULL && beg->val == cur->val)
        cur = cur->next;
      if (cur == NULL) {
        pre->next = NULL;
        return dummy.next;
      }
      pre->next = cur;
      beg = cur;
      cur = cur->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  ListNode *p = s.deleteDuplicates(head);
  while (p != NULL) {
    cout << p->val << "->";
    p = p->next;
  }
  cout << "NULL" << endl;
}
