#include <iostream>
#include <list>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// Create List
ListNode *CreateList() {
  int a;
  cout << "请输入数字：";
  cin >> a;
  if (a != -1) {
    ListNode *pHead = new ListNode(a);
    pHead->next = CreateList();
    return pHead;
  } else
    return NULL;
}

class Solution {
public:
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode Head(-1);
    ListNode *prev = &Head;
    int carry = 0;
    for (; l1 != NULL || l2 != NULL;
         l1 = l1 == NULL ? NULL : l1->next, l2 = l2 == NULL ? NULL : l2->next) {
      int a = l1 == NULL ? 0 : l1->val;
      int b = l2 == NULL ? 0 : l2->val;
      int sum = a + b + carry;
      prev->next = new ListNode(sum % 10);
      prev = prev->next;
      if (sum > 9) {
        carry = 1;
      } else {
        carry = 0;
      }
    }
    if (carry == 1)
      prev->next = new ListNode(1);
    return Head.next;
  }
};

int main() {
  ListNode *l1 = CreateList();
  ListNode *l2 = CreateList();
  Solution s;
  ListNode *l = s.addTwoNumbers(l1, l2);
  while (l != NULL) {
    cout << l->val << "->";
    l = l->next;
  }
  cout << "NULL" << endl;
}
