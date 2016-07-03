#include <iostream>

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
  int minDepth(TreeNode *root) {
    if (!root) return 0;
    if (!root->left && !root->right) return 1;
    int left = minDepth(root->left);
    int right = minDepth(root->right);
    if (left == 0 || right == 0) return 1 + max(left, right);
    return 1 + min(left, right);
  }
};

int main() {
  cout << "root: ";
  TreeNode *root = CreateTree();
  Solution s;
  int min = s.minDepth(root);
  cout << min << endl;
}
