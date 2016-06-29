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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || !head->next || k < 2)
      return head;
    ListNode dummy(-1);
    dummy.next = head;
    for (ListNode *prev = &dummy, *end = head; end; end = prev->next) {
      for (int i = 1; i < k && end; i++)
        end = end->next;
      if (!end)
        break;
      prev = reverse(prev, prev->next, end);
    }
    return dummy.next;
  }

private:
  ListNode *reverse(ListNode *prev, ListNode *begin, ListNode *end) {
    ListNode *endnext = end->next;
    for (ListNode *pre = begin, *cur = pre->next, *tmp = cur->next;
         cur != endnext; pre = cur, cur = tmp, tmp = tmp ? tmp->next : NULL)
      cur->next = pre;
    prev->next = end;
    begin->next = endnext;
    return begin;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  head = s.reverseKGroup(head, 3);
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}
