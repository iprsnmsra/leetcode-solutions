#include <queue>
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
public:
    int maxLevelSum(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (root == nullptr) return 0;

        queue<TreeNode*> q;
        q.push(root);

        int max_sum = INT_MIN;
        int best_level = 1;
        int current_level = 1;
        while (!q.empty()) {
            int level_size = q.size();
            long long level_sum = 0; 
            for (int i = 0; i < level_size; ++i) {
                TreeNode* node = q.front();
                q.pop();

                level_sum += node->val;
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            if (level_sum > max_sum) {
                max_sum = level_sum;
                best_level = current_level;
            }

            current_level++;
        }

        return best_level;
    }
};