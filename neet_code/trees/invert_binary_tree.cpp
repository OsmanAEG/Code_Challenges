// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
  void flip_nodes(TreeNode* node) {
    if(node != nullptr){
      const auto tmp_left = node->left;
      node->left = node->right;
      node->right = tmp_left;
      flip_nodes(node->left);
      flip_nodes(node->right);
    }
  }

  TreeNode* invertTree(TreeNode* root) {
    flip_nodes(root);
    return root;
  }
};

int main() {
  return 0;
}