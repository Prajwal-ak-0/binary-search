#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Delete a node at position `x` in a doubly linked list.

Approach:
1. If `x` is 1, delete the head node and update the head pointer.
2. Traverse the list to find the node at position `x`.
3. Adjust the pointers of the previous and next nodes to exclude the node at position `x`.
4. Delete the node at position `x`.

Time Complexity: O(n) - We traverse the list up to position `x`.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node* deleteNode(Node* head, int x) {
    if (x == 1) {
        Node* d = head;
        head = head->next;
        if (head) head->prev = NULL;
        delete d;
        return head;
    }

    int cnt = 1;
    Node* p = NULL;
    Node* c = head;

    while (cnt < x && c != NULL) {
        p = c;
        c = c->next;
        cnt++;
    }

    if (c == NULL) return head; // If position is out of bounds

    p->next = c->next;
    if (c->next) c->next->prev = p;
    delete c;

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    // Deleting node at position 3
    head = deleteNode(head, 3);

    // Test case explanation:
    // Doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    // After deleting node at position 3, the list should be: 1 <-> 2 <-> 4 <-> 5
    // Expected output: 1 2 4 5

    cout << "List after deleting node at position 3: ";
    printList(head);

    return 0;
}