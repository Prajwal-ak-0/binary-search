#include <iostream>

using namespace std;

struct DLLNode {
    int data;
    DLLNode* next;
    DLLNode* prev;
    DLLNode(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Reverse a doubly linked list.

Approach:
1. Traverse the list and swap the next and prev pointers for each node.
2. Move to the next node using the updated prev pointer.
3. Return the new head of the reversed list.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

DLLNode* reverseDLL(DLLNode* head) {
    DLLNode* c = head;
    DLLNode* p = NULL;
    
    while(c != NULL){
        p = c->prev;
        c->prev = c->next;
        c->next = p;
        
        c = c->prev; 
    }
    
    if (p != NULL) {
        head = p->prev;
    }
    
    return head;
}

void printList(DLLNode* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    DLLNode* head = new DLLNode(1);
    head->next = new DLLNode(2);
    head->next->prev = head;
    head->next->next = new DLLNode(3);
    head->next->next->prev = head->next;
    head->next->next->next = new DLLNode(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new DLLNode(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    DLLNode* reversedHead = reverseDLL(head);

    // Test case explanation:
    // Doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    // The reversed list is: 5 <-> 4 <-> 3 <-> 2 <-> 1
    // Expected output: 5 4 3 2 1

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}