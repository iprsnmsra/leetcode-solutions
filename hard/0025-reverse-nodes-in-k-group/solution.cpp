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
#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (!head || k == 1) return head;

        ListNode dummy(0);
        dummy.next = head;

        // Step 1: Calculate total length
        ListNode* curr = dummy.next;
        int n = 0;
        while (curr) {
            curr = curr->next;
            n++;
        }

        ListNode* pre = &dummy;
        curr = dummy.next;
        ListNode* nex = nullptr;

        // Step 2: Reverse k nodes at a time
        while (n >= k) {
            curr = pre->next; // Start of the group
            nex = curr->next; // The node we will move to the front

            // This loop moves 'nex' to the front of the group (k-1) times
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }

            // Step 3: Advance pointers for the next group
            pre = curr;
            n -= k;
        }

        return dummy.next;
    }
};