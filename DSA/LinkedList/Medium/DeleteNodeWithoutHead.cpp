#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

/*
Idea: Delete a node from a linked list without having access to the head of the list.

Approach:
1. Copy the data from the next node to the current node to be deleted.
2. Update the next pointer of the current node to skip the next node.
3. Delete the next node.

Time Complexity: O(1) - The operation is performed in constant time.
Space Complexity: O(1) - Only a few extra variables are used.
*/

void deleteNode(Node* del_node) {
    if (del_node->next) {
        del_node->data = del_node->next->data;
        Node* temp = del_node->next;
        del_node->next = del_node->next->next;
        delete temp;
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
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    // Deleting node with value 3 (without head pointer)
    Node* del_node = head->next->next; // Node with value 3
    deleteNode(del_node);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // After deleting node with value 3, the list should be: 1 -> 2 -> 4 -> 5
    // Expected output: 1 2 4 5

    cout << "List after deleting node with value 3: ";
    printList(head);

    return 0;
}