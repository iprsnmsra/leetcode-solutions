#include <vector>
#include <iostream>

using namespace std;

//  the struct TreeNode definition here because LeetCode 
// already provides it automatically!

class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        vector<TreeNode*> forest;
        
        // Optimization: Use a direct mapped boolean array instead of unordered_set
        // Constraints say values are 1 <= Node.val <= 1000.
        bool to_delete_set[1001] = {false};
        for (int val : to_delete) {
            to_delete_set[val] = true;
        }
        
        // Start DFS. The absolute root is considered a "root" initially.
        dfs(root, to_delete_set, true, forest);
        
        return forest;
    }
    
private:
    TreeNode* dfs(TreeNode* node, bool to_delete_set[], bool is_root, vector<TreeNode*>& forest) {
        if (!node) return nullptr;
        
        // Check if the current node is slated for deletion
        bool is_deleted = to_delete_set[node->val];
        
        // If it's a root of a new tree and survives, add it to the answer
        if (is_root && !is_deleted) {
            forest.push_back(node);
        }
        
        // Recursively process children. 
        // If current node IS deleted, its children become new roots (is_root = true).
        node->left = dfs(node->left, to_delete_set, is_deleted, forest);
        node->right = dfs(node->right, to_delete_set, is_deleted, forest);
        
        // If this node is deleted, return nullptr to sever the connection to its parent.
        // Otherwise, return the node itself so the parent keeps the connection.
        return is_deleted ? nullptr : node;
    }
};