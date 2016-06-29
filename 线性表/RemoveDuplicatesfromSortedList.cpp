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
    if (head == NULL)
      return NULL;
    ListNode *cur = head;
    ListNode *nextone = cur->next;
    while (nextone != NULL) {
      if (cur->val == nextone->val) {
        cur->next = nextone->next;
        nextone = cur->next;
      } else {
        cur = nextone;
        nextone = nextone->next;
      }
    }
    return head;
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
