#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

/*
Idea: Reverse a linked list.

Approach:
1. Initialize three pointers: previous (p), current (c), and forward (f).
2. Traverse the list and reverse the links.
3. Return the new head of the reversed list.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node* reverseList(Node* head) {
    Node* p = NULL;
    Node* c = head;
    Node* f = head;

    while (f != NULL) {
        f = c->next;
        c->next = p;
        p = c;
        c = f;
    }

    return p;
}

/*
Idea: Add one to a number represented by a linked list.

Approach:
1. Reverse the linked list.
2. Traverse the reversed list and add one to the first node.
3. Handle the carry if the sum is greater than 9.
4. Reverse the list again to restore the original order.

Time Complexity: O(n) - We traverse the entire list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

Node* addOne(Node* head) {
    head = reverseList(head);
    
    int c = 1;
    Node* temp = head;
    Node* prev = NULL;
    
    while(temp){
        int s = c + temp->data;
        temp->data = s % 10;
        c = s / 10;
        if(!c) break;
        
        prev = temp;
        temp = temp->next;
    }
    
    if(c){
        Node* new_node = new Node(c);
        prev->next = new_node;
    }
    
    return reverseList(head);
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 (represents number 123)
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);

    cout << "Original list: ";
    printList(head);

    Node* result = addOne(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 (represents number 123)
    // Adding one to the number gives 124.
    // The resulting linked list should be: 1 -> 2 -> 4
    // Expected output: 1 2 4

    cout << "List after adding one: ";
    printList(result);

    return 0;
}