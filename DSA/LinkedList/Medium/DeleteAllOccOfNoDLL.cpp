#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Delete all occurrences of a given value in a doubly linked list.

Approach:
1. Traverse the list to find nodes with the given value.
2. For each node with the given value, delete the node using the `deleteNode` function.
3. Adjust the head pointer if the head node is deleted.

Time Complexity: O(n^2) - In the worst case, we might need to traverse the list multiple times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node* deleteNode(Node* head, int x) {
    Node* c = head;
    Node* p = NULL;
    int cnt = 1;

    while (cnt < x && c != NULL) {
        p = c;
        c = c->next;
        cnt++;
    }

    if (c == NULL) return head;

    if (p != NULL) p->next = c->next;
    if (c->next) c->next->prev = p;
    if (c == head) head = c->next;
    delete c;

    return head;
}

void deleteAllOccurOfX(Node** head_ref, int x) {
    Node* current = *head_ref;
    int index = 1;

    while (current != NULL) {
        if (current->data == x) {
            *head_ref = deleteNode(*head_ref, index);
            current = *head_ref;
            index = 1;
        } else {
            current = current->next;
            index++;
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(2);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(2);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Original list: ";
    printList(head);

    // Deleting all occurrences of value 2
    deleteAllOccurOfX(&head, 2);

    // Test case explanation:
    // Doubly linked list: 1 <-> 2 <-> 3 <-> 2 <-> 4 <-> 2 <-> 5
    // After deleting all occurrences of value 2, the list should be: 1 <-> 3 <-> 4 <-> 5
    // Expected output: 1 3 4 5

    cout << "List after deleting all occurrences of value 2: ";
    printList(head);

    return 0;
}