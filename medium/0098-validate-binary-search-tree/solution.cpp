#include <limits>
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
public:
    bool isValidBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        return validateNode(root, LONG_MIN, LONG_MAX);
    }

private:
    bool validateNode(TreeNode* node, long long min_bound, long long max_bound) {
        if (node == nullptr) {
            return true;
        }
        if (node->val <= min_bound || node->val >= max_bound) {
            return false;
        }

        bool is_left_valid = validateNode(node->left, min_bound, node->val);
        bool is_right_valid = validateNode(node->right, node->val, max_bound);
        return is_left_valid && is_right_valid;
    }
};