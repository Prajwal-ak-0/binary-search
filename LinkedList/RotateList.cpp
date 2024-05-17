#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k) {
    // Idea: The idea is to rotate the list to the right by k places.
    // Approach: We first calculate the length of the list. We then connect the last node to the head to form a circular list.
    // We then find the new head and tail of the rotated list and break the circle to get the final rotated list.
    // Time Complexity: O(n), where n is the length of the list.
    // Space Complexity: O(1), as we are not using any extra space proportional to the input.

    if (!head || !head->next || k == 0) {
        return head;
    }

    int len = 1;
    ListNode* temp = head;
    while(temp->next){
        temp = temp->next;
        len++;
    }

    temp->next = head;

    k = k % len;
    int stepsToNewHead = len - k;
    ListNode* newTail = temp;
    while (stepsToNewHead--) {
        newTail = newTail->next;
    }
    ListNode* newHead = newTail->next;

    newTail->next = nullptr;

    return newHead;
}

int main() {
    // Test Case: The linked list is 1->2->3->4->5, k = 2
    // After rotating the list to the right by 2 places, the list becomes 4->5->1->2->3.
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = rotateRight(head, 2);

    while(result != NULL) {
        std::cout << result->val << " ";
        result = result->next;
    }

    return 0;
}