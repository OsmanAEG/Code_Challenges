#include<algorithm>

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
  int count_max_depth(TreeNode* node, int curr_max){
    if(node != nullptr){
      curr_max += 1;

      int left_max = count_max_depth(node->left, curr_max);
      int right_max = count_max_depth(node->right, curr_max);

      curr_max = std::max(left_max, right_max);
    }

    return curr_max;
  }

  int maxDepth(TreeNode* root) {
    const auto max_depth = count_max_depth(root, 0);
    return max_depth;
  }
};

int main(){
  return 0;
}
