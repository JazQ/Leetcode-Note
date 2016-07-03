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
  int maxDepth(TreeNode *root) {
    if (!root) return 0;
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    return 1 + max(left, right);
  }
};

int main() {
  cout << "root: ";
  TreeNode *root = CreateTree();
  Solution s;
  int min = s.maxDepth(root);
  cout << min << endl;
}
