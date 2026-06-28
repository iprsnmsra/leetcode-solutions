#include <unordered_map>
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
    int pathSum(TreeNode* root, int targetSum) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        unordered_map<long long, int> prefix_map;
        prefix_map[0] = 1;

        return dfs(root, 0, targetSum, prefix_map);
    }

private:
    int dfs(TreeNode* node, long long current_sum, int targetSum, unordered_map<long long, int>& prefix_map) {
        if (node == nullptr) {
            return 0;
        }
        current_sum += node->val;
        
        int paths = 0;
        if (prefix_map.count(current_sum - targetSum)) {
            paths += prefix_map[current_sum - targetSum];
        }
        prefix_map[current_sum]++;
        paths += dfs(node->left, current_sum, targetSum, prefix_map);
        paths += dfs(node->right, current_sum, targetSum, prefix_map);
        prefix_map[current_sum]--;

        return paths;
    }
};