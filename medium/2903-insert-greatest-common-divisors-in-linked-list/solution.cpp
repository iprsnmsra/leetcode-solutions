#include <numeric>

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (!head || !head->next) {
            return head;
        }

        ListNode* curr = head;
        while (curr != nullptr && curr->next != nullptr) {

            ListNode* next_node = curr->next;
            
            ListNode* gcd_node = new ListNode(std::gcd(curr->val, next_node->val));

            curr->next = gcd_node;
            gcd_node->next = next_node;
            curr = next_node;
        }

        return head;
    }
};