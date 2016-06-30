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
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> result;
    stack<TreeNode *> stk;
    TreeNode *p = root;
    while (!stk.empty() || p != NULL) {
      if (p != NULL) {
        stk.push(p);
        p = p->left;
      } else {
        p = stk.top();
        stk.pop();
        result.push_back(p->val);
        p = p->right;
      }
    }
    return result;
  }
};

int main() {
  cout << "请输入头结点：";
  TreeNode *head = CreateTree();
  Solution s;
  vector<int> result = s.inorderTraversal(head);
  for (auto i : result) cout << i << " ";
  cout << endl;
}
