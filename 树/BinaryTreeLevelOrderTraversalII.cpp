#include <iostream>
#include <queue>
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
  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> result;
    queue<TreeNode *> cur, next;
    if (root != NULL) cur.push(root);
    while (!cur.empty()) {
      vector<int> level;
      while (!cur.empty()) {
        TreeNode *p = cur.front();
        cur.pop();
        level.push_back(p->val);

        if (p->left != NULL) next.push(p->left);
        if (p->right != NULL) next.push(p->right);
      }
      result.push_back(level);
      swap(cur, next);
    }
    reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  cout << "请输入头结点：";
  TreeNode *head = CreateTree();
  Solution s;
  vector<vector<int>> result = s.levelOrderBottom(head);
  for (auto i : result) {
    for (auto j : i) cout << j << " ";
    cout << endl;
  }
}
