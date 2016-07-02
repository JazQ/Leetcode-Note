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
  bool isBalanced(TreeNode *root) {
    if (!root) return true;
    return treeheight(root) > 0;
  }

 private:
  int treeheight(TreeNode *root) {
    if (!root) return 0;

    int left = treeheight(root->left);
    int right = treeheight(root->right);
    if (left < 0 || right < 0 || abs(left - right) > 1) return -1;
    return max(left, right) + 1;
  }
};

int main() {
  cout << "请输入root：" << endl;
  TreeNode *root = CreateTree();
  Solution s;
  bool ifr = s.isBalanced(root);
  if (ifr)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
