#include <iostream>
#include <stack>
#include <vector>

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
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> s;
    TreeNode *p = root, *q = NULL;
    do {
      while (p) {
        s.push(p);
        p = p->left;
      }
      q = NULL;
      while (!s.empty()) {
        p = s.top();
        s.pop();
        if (p->right == q) {
          result.push_back(p->val);
          q = p;
        } else {
          s.push(p);
          p = p->right;
          break;
        }
      }
    } while (!s.empty());
    return result;
  }
};
