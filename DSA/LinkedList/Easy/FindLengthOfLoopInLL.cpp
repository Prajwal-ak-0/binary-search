#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

/*
Idea: Find the length of the loop in a linked list.

Approach:
1. Use two pointers: slow (s) and fast (f).
2. Move the slow pointer one step and the fast pointer two steps at a time.
3. If the slow pointer and fast pointer meet, there is a loop.
4. To find the length of the loop, keep one pointer fixed and move the other pointer until they meet again, counting the number of steps.

Time Complexity: O(n) - We traverse the entire list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int countNodesinLoop(Node *head) {
    Node* s = head;
    Node* f = head;

    while (f != NULL && f->next != NULL) {
        s = s->next;
        f = f->next->next;
        if (f == s) break;
    }

    if (f == NULL || f->next == NULL) return 0;

    int count = 1;
    Node* c = s->next;
    while (c != s) {
        c = c->next;
        count++;
    }

    return count;
}

int main() {
    // Creating a linked list with a loop: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = head->next->next; // Creating a loop

    int result = countNodesinLoop(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5 -> 3 (loop starts here)
    // The loop length is 3 (3 -> 4 -> 5 -> 3).
    // Expected output: 3

    cout << "The length of the loop in the linked list is " << result << endl;

    // Creating a linked list without a loop: 1 -> 2 -> 3 -> 4 -> 5
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    result = countNodesinLoop(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // There is no loop in the linked list.
    // Expected output: 0

    cout << "The length of the loop in the linked list is " << result << endl;

    return 0;
}