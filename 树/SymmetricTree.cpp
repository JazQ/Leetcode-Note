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

// class Solution {
//  public:
//   bool isSymmetric(TreeNode *root) {
//     if (root == NULL) return true;
//     return Issymmetric(root->left, root->right);
//   }
//
//  private:
//   bool Issymmetric(TreeNode *left, TreeNode *right) {
//     if (!left && !right) return true;
//     if (!left || !right) return false;
//     if (left->val != right->val) return false;
//     return Issymmetric(left->left, right->right) &&
//            Issymmetric(left->right, right->left);
//   }
// };

class Solution {
 public:
  bool isSymmetric(TreeNode *root) {
    if (!root) return true;
    stack<TreeNode *> s;
    s.push(root->right);
    s.push(root->left);

    while (!s.empty()) {
      TreeNode *left = s.top();
      s.pop();
      TreeNode *right = s.top();
      s.pop();

      if (!left && !right) continue;
      if (!left || !right) return false;
      if (left->val != right->val) return false;
      s.push(right->left);
      s.push(left->right);
      s.push(right->right);
      s.push(left->left);
    }
    return true;
  }
};

int main(int argc, char *argv[]) {
  cout << "root: " << endl;
  TreeNode *root = CreateTree();
  Solution s;
  bool ifr = s.isSymmetric(root);
  if (ifr)
    cout << "True" << endl;
  else
    cout << "False" << endl;
}
