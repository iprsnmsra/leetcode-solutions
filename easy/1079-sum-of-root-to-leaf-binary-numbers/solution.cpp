#include <iostream>

using namespace std;

// Definition for a binary tree node.
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return dfs(root, 0);
    }

private:
    int dfs(TreeNode* node, int current_val) {
        // Base case 1: Empty node contributes 0 to the total sum
        if (node == nullptr) {
            return 0;
        }
        current_val = (current_val << 1) | node->val;
        if (node->left == nullptr && node->right == nullptr) {
            return current_val;
        }
        return dfs(node->left, current_val) + dfs(node->right, current_val);
    }
};