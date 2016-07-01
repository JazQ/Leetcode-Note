#include <iostream>
#include <stack>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode *CreateTree() {
  int a;
  cin >> a;
  if (a != 0) {
    TreeNode *head = new TreeNode(a);
    cout << "请输入" << a << "的左节点：";
    head->left = CreateTree();
    cout << "请输入" << a << "的右节点：";
    head->right = CreateTree();
    return head;
  } else
    return NULL;
}

class Solution {
 public:
  bool isSameTree(TreeNode *p, TreeNode *q) {
    stack<TreeNode *> s;
    s.push(p);
    s.push(q);

    while (!s.empty()) {
      q = s.top();
      s.pop();
      p = s.top();
      s.pop();

      if (!p && !q) continue;
      if (!p || !q) return false;
      if (p->val != q->val) return false;

      s.push(p->left);
      s.push(q->left);

      s.push(p->right);
      s.push(q->right);
    }
    return true;
  }
};

int main() {
  TreeNode *p = CreateTree();
  TreeNode *q = CreateTree();
  Solution s;
  bool v = s.isSameTree(p, q);
  if (v)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
