#include <algorithm>
#include <climits>
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
    int global_max = INT_MIN;

public:
    int maxPathSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        dfs(root);
        return global_max;
    }

private:
    int dfs(TreeNode* node) {
        if (!node) return 0;
        int left_branch = max(0, dfs(node->left));
        int right_branch = max(0, dfs(node->right));
        int current_arch = node->val + left_branch + right_branch;

        global_max = max(global_max, current_arch);

        return node->val + max(left_branch, right_branch);
    }
};