/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* prev = nullptr;
        ListNode* curr = slow;
        
        while (curr != nullptr) {
            ListNode* next_temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next_temp;
        }
        int max_sum = 0;
        ListNode* start = head;
        
        while (prev != nullptr) {
            int current_twin_sum = start->val + prev->val;
            if (current_twin_sum > max_sum) {
                max_sum = current_twin_sum;
            }
            start = start->next;
            prev = prev->next;
        }
        
        return max_sum;
    }
};