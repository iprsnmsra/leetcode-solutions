#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        // Optimization: Fast I/O for competitive programming execution speeds
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Edge Case: Topography requires at least 3 nodes to form a critical point
        if (!head || !head->next || !head->next->next) {
            return {-1, -1};
        }

        // 1. O(1) Memory State Registers
        int first_idx = -1;
        int last_idx = -1;
        int min_dist = INT_MAX;
        
        // 2. Sliding Window Pointers
        ListNode* prev = head;
        ListNode* curr = head->next;
        int current_idx = 1;

        // 3. The Single-Pass Topographical Sweep
        while (curr->next != nullptr) {
            ListNode* next_node = curr->next;
            
            // Branch Prediction Optimization: Grouping the topographical check
            bool is_maxima = (curr->val > prev->val) && (curr->val > next_node->val);
            bool is_minima = (curr->val < prev->val) && (curr->val < next_node->val);
            
            if (is_maxima || is_minima) {
                if (first_idx == -1) {
                    // Lock the first critical point to calculate absolute max distance later
                    first_idx = current_idx;
                } else {
                    // Instantly calculate adjacency gap for min distance
                    min_dist = min(min_dist, current_idx - last_idx);
                }
                // Cascade the state forward
                last_idx = current_idx;
            }
            
            // Advance the hardware pointers
            prev = curr;
            curr = next_node;
            current_idx++;
        }

        // 4. Mathematical Resolution Check
        if (min_dist == INT_MAX) {
            return {-1, -1};
        }
        
        return {min_dist, last_idx - first_idx};
    }
};