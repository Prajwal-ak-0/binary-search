#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Insert a new node at a given position in a doubly linked list.

Approach:
1. Create a new node with the given data.
2. Traverse the list to find the node at position `pos`.
3. Adjust the pointers of the previous and next nodes to include the new node.
4. Return the head of the list.

Time Complexity: O(n) - We traverse the list up to position `pos`.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node *addNode(Node *head, int pos, int data) {
    Node* new_node = new Node(data);
    
    Node* p = NULL;
    Node* temp = head;
    
    int cnt = 0;
    
    while(cnt <= pos){
        cnt++;
        p = temp;
        temp = temp->next;
    }
    
    new_node->next = temp;
    new_node->prev = p;
    p->next = new_node;
    if(temp) temp->prev = new_node;
    
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

    // Inserting node with value 6 at position 2
    head = addNode(head, 2, 6);

    // Test case explanation:
    // Doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    // After inserting node with value 6 at position 2, the list should be: 1 <-> 2 <-> 6 <-> 3 <-> 4 <-> 5
    // Expected output: 1 2 6 3 4 5

    cout << "List after inserting node with value 6 at position 2: ";
    printList(head);

    return 0;
}