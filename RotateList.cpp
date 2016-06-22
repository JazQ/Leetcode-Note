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
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == NULL || k == 0)
      return head;
    ListNode *len = head;
    int lenth = 1;
    while (len->next) {
      lenth++;
      len = len->next;
    }
    k = lenth - k % lenth;
    len->next = head;
    for (int i = 0; i < k; i++)
      len = len->next;
    head = len->next;
    len->next = NULL;
    return head;
  }
};

int main() {
  ListNode *head = CreateList();
  Solution s;
  head = s.rotateRight(head, 1);
  while (head != NULL) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}
