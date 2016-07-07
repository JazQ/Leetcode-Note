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
  if (a > 0) {
    ListNode* head = new ListNode(a);
    head->next = CreateList();
    return head;
  } else
    return NULL;
}

class Solution {
 public:
  ListNode* oddEvenList(ListNode* head) {
    if (!head || !head->next || !head->next->next) return head;
    ListNode* oddnode = head;
    ListNode* evenstart = head->next;
    ListNode* evennode = head->next;
    while (oddnode->next && evennode->next) {
      oddnode->next = evennode->next;
      oddnode = evennode->next;
      evennode->next = oddnode->next;
      evennode = oddnode->next;
    }
    oddnode->next = evenstart;
    return head;
  }
};

int main() {
  ListNode* head = CreateList();
  Solution s;
  head = s.oddEvenList(head);
  while (head) {
    cout << head->val << "->";
    head = head->next;
  }
  cout << "NULL" << endl;
}
