#include <vector>
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        TreeNode* nodes[100005] = {nullptr};
        bool is_child[100005] = {false};

        for (const auto& desc : descriptions) {
            int p_val = desc[0];
            int c_val = desc[1];
            bool is_left = desc[2];

            if (!nodes[p_val]) {
                nodes[p_val] = new TreeNode(p_val);
            }
            if (!nodes[c_val]) {
                nodes[c_val] = new TreeNode(c_val);
            }

            if (is_left) {
                nodes[p_val]->left = nodes[c_val];
            } else {
                nodes[p_val]->right = nodes[c_val];
            }
            is_child[c_val] = true;
        }
        for (const auto& desc : descriptions) {
            int p_val = desc[0];
            if (!is_child[p_val]) {
                return nodes[p_val];
            }
        }

        return nullptr;
    }
};