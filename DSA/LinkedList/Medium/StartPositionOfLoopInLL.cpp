#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Detect the start position of the loop in a linked list.

Approach:
1. Use two pointers: slow (s) and fast (f).
2. Move the slow pointer one step and the fast pointer two steps at a time.
3. If the slow pointer and fast pointer meet, there is a loop.
4. To find the start of the loop, move one pointer to the head and keep the other at the meeting point.
5. Move both pointers one step at a time until they meet again. The meeting point is the start of the loop.

Time Complexity: O(n) - We traverse the entire list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

ListNode *detectCycle(ListNode *head) {
    ListNode* s = head;
    ListNode* f = head;

    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
        if (f == s) break;
    }

    if (f == NULL || f->next == NULL) return NULL;

    s = head;
    while (s != f) {
        s = s->next;
        f = f->next;
    }

    return s;
}

int main() {
    // Creating a linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = head->next->next; // Creating a loop

    ListNode* result = detectCycle(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    // The start of the loop is at node with value 3.
    // Expected output: 3

    if (result != NULL) {
        cout << "The start of the loop is at node with value " << result->val << endl;
    } else {
        cout << "There is no loop in the linked list." << endl;
    }

    // Creating a linked list without a loop: 1 -> 2 -> 3 -> 4 -> 5
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    result = detectCycle(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // There is no loop in the linked list.
    // Expected output: There is no loop in the linked list.

    if (result != NULL) {
        cout << "The start of the loop is at node with value " << result->val << endl;
    } else {
        cout << "There is no loop in the linked list." << endl;
    }

    return 0;
}