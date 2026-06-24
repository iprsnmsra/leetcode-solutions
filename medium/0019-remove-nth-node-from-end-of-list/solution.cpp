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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        ListNode* slow = head;

        // Step 1: Advance fast pointer by n steps to create a gap of n
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Edge Case: If fast is NULL, n equals list length.
        // This means we need to delete the head node.
        if (!fast) {
            ListNode* newHead = head->next;
            // delete head; // Optional: Good practice in real dev to prevent memory leaks
            return newHead;
        }

        // Step 2: Move both pointers until fast reaches the last node
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // Step 3: Skip the nth node from the end
        ListNode* nodeToDelete = slow->next;
        slow->next = slow->next->next;
        
        // delete nodeToDelete; // Optional: Free memory
        
        return head;
    }
};