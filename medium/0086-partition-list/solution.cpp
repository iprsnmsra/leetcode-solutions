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
    ListNode* partition(ListNode* head, int x) {
        // Optimization: Fast I/O
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        // Use stack-allocated dummy nodes to avoid 'new' overhead
        ListNode small_head(0);
        ListNode large_head(0);
        
        ListNode* small = &small_head;
        ListNode* large = &large_head;
        
        while (head) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            } else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        
        // Connect the two lists
        large->next = nullptr;        
        small->next = large_head.next; 
        return small_head.next;
    }
};