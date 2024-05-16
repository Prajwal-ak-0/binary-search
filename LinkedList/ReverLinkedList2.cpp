#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int left, int right) {
    // Idea: The idea is to reverse the sublist of the linked list from position left to right.
    // Approach: We first traverse to the node just before the left position. We then reverse the sublist from left to right.
    // After reversing, we connect the reversed sublist back to the main list.
    // Time Complexity: O(n), where n is the length of the list.
    // Space Complexity: O(1), as we are not using any extra space proportional to the input.

    ListNode *dummy = new ListNode(0);
    dummy->next = head;

    ListNode *curr = head;
    ListNode *leftPrev = dummy;

    for(int i=0;i<left-1;i++){
        leftPrev = leftPrev->next;
        curr = curr->next;
    }

    ListNode *subListHead = curr;
    ListNode *forw = NULL;
    ListNode *prev = NULL;

    for(int i=0; i<= right - left; i++){
        forw = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forw;
    }

    leftPrev->next = prev;
    subListHead->next = curr;

    return dummy->next;
}

int main() {
    // Test Case: The linked list is 1->2->3->4->5, left = 2, right = 4
    // After reversing the sublist from position 2 to 4, the list becomes 1->4->3->2->5.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = reverseBetween(head, 2, 4);

    while(result != NULL) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}