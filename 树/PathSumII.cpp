#include <iostream>
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
  vector<vector<int>> pathSum(TreeNode *root, int sum) {
    vector<vector<int>> result;
    vector<int> cur;
    if (root != NULL) pathSum(root, sum, cur, result);
    return result;
  }

 private:
  void pathSum(TreeNode *root, int sum, vector<int> &cur,
               vector<vector<int>> &result) {
    cur.push_back(root->val);
    if (root->left == NULL && root->right == NULL) {
      if (sum == root->val) result.push_back(cur);
    }
    if (root->left != NULL) pathSum(root->left, sum - root->val, cur, result);
    if (root->right != NULL) pathSum(root->right, sum - root->val, cur, result);
    cur.pop_back();
  }
};
