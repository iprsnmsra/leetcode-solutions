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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        
        // Use a dummy node to handle the head swap cleanly
        ListNode dummy(0); 
        dummy.next = head;
        
        ListNode* prev = &dummy;
        ListNode* curr = head;
        
        while (curr && curr->next) {
            // Identify nodes to swap
            ListNode* first = curr;
            ListNode* second = curr->next;
            
            // The Swap
            prev->next = second;
            first->next = second->next;
            second->next = first;
            
            // Advance pointers for next iteration
            prev = first;
            curr = first->next;
        }
        
        return dummy.next;
    }
};