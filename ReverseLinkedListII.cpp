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
  cout << "请输入数字：";
  cin >> a;
  if (a != -1) {
    ListNode *pHead = new ListNode(a);
    pHead->next = CreateList();
    return pHead;
  }
  return NULL;
}

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode dummy(-1);
    dummy.next = head;

    ListNode *prev = &dummy;
    for (int i = 0; i < m - 1; i++)
      prev = prev->next;
    ListNode *prelast = prev;
    prev = prelast->next;
    ListNode *cur = prev->next;
    for (int i = m; i < n; i++) {
      prev->next = cur->next;
      cur->next = prelast->next;
      prelast->next = cur;
      cur = prev->next;
    }
    return dummy.next;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  ListNode *head1 = s.reverseBetween(head, 2, 4);
  while (head1 != NULL) {
    cout << head1->val << "-->";
    head1 = head1->next;
  }
  cout << "NULL" << endl;
}
