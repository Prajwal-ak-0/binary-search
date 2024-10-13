#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Remove duplicates from a sorted doubly linked list.

Approach:
1. Traverse the list with a pointer.
2. If the current node's data is equal to the next node's data, delete the next node.
3. Adjust the pointers of the current and next nodes accordingly.
4. Continue until the end of the list is reached.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node* removeDuplicates(Node* head) {
    if (!head || !head->next) return head;
    
    Node* temp = head;
    
    while (temp && temp->next) {
        if (temp->data == temp->next->data) {
            Node* duplicate = temp->next;
            
            temp->next = duplicate->next;
            
            if (duplicate->next) {
                duplicate->next->prev = temp;
            }
            
            delete duplicate;
        } else {
            temp = temp->next;
        }
    }
    
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
    // Creating a sorted doubly linked list with duplicates: 1 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(2);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(3);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next = new Node(4);
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    // Test case explanation:
    // Sorted doubly linked list with duplicates: 1 <-> 2 <-> 2 <-> 3 <-> 4 <-> 4 <-> 5
    // After removing duplicates, the list should be: 1 <-> 2 <-> 3 <-> 4 <-> 5
    // Expected output: 1 2 3 4 5

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}