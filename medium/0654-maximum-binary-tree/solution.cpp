#include <vector>
#include <iostream>

using namespace std;

// Definition for a binary tree node. (Provided by LeetCode internally)
// struct TreeNode {
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// };

class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        vector<TreeNode*> st;

        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while (!st.empty() && st.back()->val < num) {
                curr->left = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                st.back()->right = curr;
            }
            st.push_back(curr);
        }
        return st.front();
    }
};