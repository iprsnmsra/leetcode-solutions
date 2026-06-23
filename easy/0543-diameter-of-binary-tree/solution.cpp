#include <algorithm>
#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
    // Global state to track the absolute maximum 'Arch' found anywhere in the tree
    int max_diameter = 0;

public:
    int diameterOfBinaryTree(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        dfs(root);
        
        return max_diameter;
    }

private:
    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left_depth = dfs(node->left);
        int right_depth = dfs(node->right);

        int current_arch = left_depth + right_depth;

        max_diameter = max(max_diameter, current_arch);

        return 1 + max(left_depth, right_depth);
    }
};