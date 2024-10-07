#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Detect if a linked list has a cycle.

Approach:
1. Use two pointers: slow (s) and fast (f).
2. Move the slow pointer one step and the fast pointer two steps at a time.
3. If the slow pointer and fast pointer meet, there is a cycle.
4. If the fast pointer reaches the end, there is no cycle.

Time Complexity: O(n) - We traverse the entire list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

bool hasCycle(ListNode *head) {
    ListNode* s = head;
    ListNode* f = head;

    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
        if (f == s) return true;
    }

    return false;
}

int main() {
    // Creating a linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // Creating a loop

    bool result = hasCycle(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    // The list has a cycle.
    // Expected output: true

    cout << "The linked list has a cycle: " << (result ? "true" : "false") << endl;

    // Creating a linked list without a loop: 1 -> 2 -> 3 -> 4 -> 5
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    result = hasCycle(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // There is no cycle in the linked list.
    // Expected output: false

    cout << "The linked list has a cycle: " << (result ? "true" : "false") << endl;

    return 0;
}