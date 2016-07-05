#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) return NULL;
    TreeNode* phead = new TreeNode(preorder[0]);
    int i = 0;
    while (preorder[0] != inorder[i]) i++;
    preorder.erase(preorder.begin());
    vector<int>::iterator inin = inorder.begin();
    vector<int> inorderleft, inorderright;
    if (i != 0) inorderleft = vector<int>(inin, inin + i);
    if (i != inorder.size() - 1)
      inorderright = vector<int>(inin + i + 1, inorder.end());
    phead->left = buildTree(preorder, inorderleft);
    phead->right = buildTree(preorder, inorderright);
    return phead;
  }
};
