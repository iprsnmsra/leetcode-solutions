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
    int maxZ = 0; 

    void dfs(TreeNode* node, bool goLeft, int steps) {
        if (steps > maxZ) {
            maxZ = steps;
        }
        if (node->left) {
            dfs(node->left, false, goLeft ? steps + 1 : 1);
        }
        if (node->right) {
            dfs(node->right, true, !goLeft ? steps + 1 : 1);
        }
    }

public:
    int longestZigZag(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (!root) return 0;
        if (root->left) dfs(root->left, false, 1);
        if (root->right) dfs(root->right, true, 1);

        return maxZ;
    }
};