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
public:
    int goodNodes(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        return dfs(root, root->val);
    }

private:
    int dfs(TreeNode* node, int max_so_far) {
        if (node == nullptr) {
            return 0;
        }

        int is_good = 0;
        if (node->val >= max_so_far) {
            is_good = 1;
            max_so_far = node->val; 
        }
        int left_good = dfs(node->left, max_so_far);
        int right_good = dfs(node->right, max_so_far);
        return is_good + left_good + right_good;
    }
};