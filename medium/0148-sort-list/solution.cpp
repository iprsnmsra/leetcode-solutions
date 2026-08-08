
// Definition for singly-linked list (provided by LeetCode).
/*
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
*/

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(NULL);
        if (!head || !head->next) return head;
        int length = 0;
        ListNode* curr = head;
        while (curr) {
            length++;
            curr = curr->next;
        }
        ListNode dummy(0);
        dummy.next = head;
        for (int step = 1; step < length; step <<= 1) {
            ListNode* tail = &dummy;
            curr = dummy.next;
            
            while (curr) {
                ListNode* left = curr;
                ListNode* right = split(left, step);
                curr = split(right, step);
                tail = merge(left, right, tail);
            }
        }
        
        return dummy.next;
    }

private:
    ListNode* split(ListNode* head, int n) {
        if (!head) return nullptr;
        for (int i = 1; head->next && i < n; ++i) {
            head = head->next;
        }
        ListNode* right = head->next;
        head->next = nullptr; 
        
        return right;
    }
    ListNode* merge(ListNode* l1, ListNode* l2, ListNode* tail) {
        ListNode* curr = tail;
        
        while (l1 && l2) {
            if (l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            } else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = (l1 != nullptr) ? l1 : l2;
        while (curr->next) {
            curr = curr->next;
        }
        
        return curr;
    }
};