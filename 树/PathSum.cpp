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
    TreeNode *root = new TreeNode(a);
    cout << a << "左: ";
    root->left = CreateTree();
    cout << a << "右: ";
    root->right = CreateTree();
    return root;
  }
  return NULL;
}

class Solution {
 public:
  bool hasPathSum(TreeNode *root, int sum) {
    if (!root) return false;
    stack<pair<TreeNode *, int>> s;
    s.push(make_pair(root, root->val));
    while (!s.empty()) {
      TreeNode *p = s.top().first;
      int dsum = s.top().second;
      s.pop();
      if (!p->left && !p->right && dsum == sum) return true;
      if (p->left) s.push(make_pair(p->left, p->left->val + dsum));
      if (p->right) s.push(make_pair(p->right, p->right->val + dsum));
    }
    return false;
  }
};

int main() {
  cout << "root: ";
  TreeNode *root = CreateTree();
  int sum = 1;
  Solution s;
  bool ifr = s.hasPathSum(root, sum);
  if (ifr)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
