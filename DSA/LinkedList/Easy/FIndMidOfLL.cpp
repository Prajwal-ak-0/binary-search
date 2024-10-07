#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Find the middle node of a linked list.

Approach:
1. Use two pointers: fast (f) and slow (s).
2. Move the fast pointer two steps and the slow pointer one step at a time.
3. When the fast pointer reaches the end, the slow pointer will be at the middle.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

ListNode* middleNode(ListNode* head) {
    ListNode* f = head;
    ListNode* s = head;

    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
    }

    return s;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    ListNode* result = middleNode(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // The middle node is 3.
    // Expected output: 3

    cout << "The middle node of the linked list is " << result->val << endl;

    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);

    result = middleNode(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // The middle node is 4.
    // Expected output: 4

    cout << "The middle node of the linked list is " << result->val << endl;

    return 0;
}