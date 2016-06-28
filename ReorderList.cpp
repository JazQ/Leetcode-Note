#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  void reorderList(ListNode *head) {
    if (!head || !head->next)
      return;
    ListNode *slow = head, *fast = head, *prev = slow;
    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }
    prev->next = NULL;
    slow = Reverse(slow);
    ListNode *cur = head;
    while (cur->next) {
      ListNode *temp = cur->next;
      cur->next = slow;
      slow = slow->next;
      cur->next->next = temp;
      cur = temp;
    }
    cur->next = slow;
  }

private:
  ListNode *Reverse(ListNode *head) {
    if (!head->next)
      return head;
    ListNode *prev = head;
    for (ListNode *cur = prev->next, *temp = cur->next; cur;
         prev = cur, cur = temp, temp = temp ? temp->next : NULL)
      cur->next = prev;
    head->next = NULL;
    return prev;
  }
};

// 用hash表
// class Solution {
// public:
//   void reorderList(ListNode *head) {
//     ListNode dummy(-1);
//     dummy.next = head;
//     ListNode *len = &dummy;
//     int lenth = 0;
//     unordered_map<int, ListNode *> nodes;
//     while (len->next) {
//       lenth++;
//       len = len->next;
//       nodes[lenth] = len;
//     }
//     if (lenth < 3)
//       return;
//     for (int k = lenth; k > lenth / 2 + 1; k--) {
//       nodes[lenth + 1 - k]->next = nodes[k];
//       nodes[k]->next = nodes[lenth + 2 - k];
//     }
//     nodes[lenth / 2 + 1]->next = NULL;
//     return;
//   }
// };
