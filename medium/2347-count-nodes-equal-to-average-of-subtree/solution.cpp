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
private:
    struct SubtreeState {
        int sum;
        int count;
    };
    SubtreeState dfs(TreeNode* node, int& match_count) {
        if (!node) {
            return {0, 0};
        }
        SubtreeState left_state = dfs(node->left, match_count);
        SubtreeState right_state = dfs(node->right, match_count);
        int current_sum = left_state.sum + right_state.sum + node->val;
        int current_count = left_state.count + right_state.count + 1;
        if (node->val == current_sum / current_count) {
            match_count++;
        }
        return {current_sum, current_count};
    }

public:
    int averageOfSubtree(TreeNode* root) {
        int match_count = 0; 
        
        dfs(root, match_count);
        
        return match_count;
    }
};