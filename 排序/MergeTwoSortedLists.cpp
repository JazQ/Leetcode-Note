#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* CreateList() {
  int a;
  cin >> a;
  if (a >= 0) {
    ListNode* head = new ListNode(a);
    head->next = CreateList();
    return head;
  }
  return NULL;
}

class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1 || !l2) return l1 ? l1 : l2;
    ListNode dummy(-1);
    ListNode* p = &dummy;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        p->next = l1;
        p = l1;
        l1 = l1->next;
      } else {
        p->next = l2;
        p = l2;
        l2 = l2->next;
      }
    }
    if (!l1)
      p->next = l2;
    else
      p->next = l1;
    return dummy.next;
  }
};
