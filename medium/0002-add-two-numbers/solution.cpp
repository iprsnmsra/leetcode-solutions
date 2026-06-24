#include <iostream> // Required for input/output operations (e.g., std::cout, std::endl)
#include <vector>   // Required for std::vector to easily create test linked lists

// IMPORTANT: Assuming ListNode struct is already defined in the environment.
// For example, it might be provided in a header file like ./precompiled/ListNode.h.
// Therefore, we do NOT define it here to avoid "redefinition of 'ListNode'" errors.
// The structure is typically:
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };


// Solution class to encapsulate the addTwoNumbers function
class Solution {
public:
    // Function to add two numbers represented by linked lists
    // l1: Pointer to the head of the first linked list.
    // l2: Pointer to the head of the second linked list.
    // Returns: Pointer to the head of the new linked list representing the sum.
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head node for the result list.
        // This simplifies handling the creation of the first actual node
        // and avoids special casing an empty result list.
        ListNode* dummyHead = new ListNode(0);

        // 'current' pointer will traverse the new list, building it node by node.
        ListNode* current = dummyHead;

        // 'carry' variable to store any carry-over digit from a sum (e.g., 1 from 17).
        int carry = 0;

        // Loop continues as long as there are digits remaining in either input list
        // OR there is a carry-over from the last addition. This ensures all digits
        // and any final carry are processed.
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            // Get the value from the current node of l1.
            // If l1 is null (end of list), treat its value as 0.
            int val1 = (l1 != nullptr) ? l1->val : 0;

            // Get the value from the current node of l2.
            // If l2 is null (end of list), treat its value as 0.
            int val2 = (l2 != nullptr) ? l2->val : 0;

            // Calculate the sum of the current digits from both lists and the carry.
            int sum = val1 + val2 + carry;

            // Determine the new carry for the next iteration.
            // For example, if sum is 17, carry becomes 1 (17 / 10).
            carry = sum / 10;

            // Create a new node for the result list.
            // The value of this node is the current digit of the sum (sum % 10).
            // For example, if sum is 17, the digit is 7 (17 % 10).
            current->next = new ListNode(sum % 10);

            // Move the 'current' pointer to the newly created node,
            // preparing for the next digit's addition.
            current = current->next;

            // Move to the next node in l1 if it exists.
            if (l1 != nullptr) {
                l1 = l1->next;
            }
            // Move to the next node in l2 if it exists.
            if (l2 != nullptr) {
                l2 = l2->next;
            }
        }

        // The actual result list starts from dummyHead->next.
        // The dummyHead itself was just a temporary placeholder.
        ListNode* result = dummyHead->next;

        // Free the memory allocated for the dummy head node.
        delete dummyHead;

        // Return the head of the resulting linked list.
        return result;
    }
};

// --- Helper Functions for Testing (Optional, but useful if you need to build/print lists externally) ---
// These functions assume ListNode is already defined in the environment.

// Function to create a linked list from a vector of integers.
// This is useful for setting up test cases easily.
ListNode* createList(const std::vector<int>& nums) {
    if (nums.empty()) {
        return nullptr; // Return null for an empty vector
    }
    // Create the head node using the first element
    ListNode* head = new ListNode(nums[0]);
    ListNode* current = head;
    // Iterate through the rest of the vector to create subsequent nodes
    for (size_t i = 1; i < nums.size(); ++i) {
        current->next = new ListNode(nums[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list to the console.
// Helps in verifying the output of the addTwoNumbers function.
void printList(ListNode* head) {
    ListNode* current = head;
    std::cout << "[";
    while (current != nullptr) {
        std::cout << current->val;
        if (current->next != nullptr) {
            std::cout << ","; // Add comma if it's not the last element
        }
        current = current->next;
    }
    std::cout << "]" << std::endl;
}

// Function to delete a linked list and free its memory.
// Essential for preventing memory leaks in C++ when using 'new'.
void deleteList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        ListNode* nextNode = current->next; // Store next node before deleting current
        delete current; // Delete the current node
        current = nextNode; // Move to the next node
    }
}