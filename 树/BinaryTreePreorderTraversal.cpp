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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> left;
    if (root != NULL)
      left.push(root);
    while (!left.empty()) {
      TreeNode *p = left.top();
      left.pop();
      result.push_back(p->val);

      if (p->right != NULL)
        left.push(p->right);
      if (p->left != NULL)
        left.push(p->left);
    }
    return result;
  }
};

int main() {
  TreeNode *head = CreateTree();
  Solution s;
  vector<int> result = s.preorderTraversal(head);
  for (auto i : result)
    cout << i << " ";
  cout << endl;
}
