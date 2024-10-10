#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

// Approach 1: Counting elements
// Idea: Count the number of 0s, 1s, and 2s, then overwrite the linked list with the counted values.
// Time Complexity: O(n) - We traverse the list twice.
// Space Complexity: O(1) - No extra space is used except for counters.
Node* segregateCount(Node* head) {
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    
    Node* temp = head;
    
    while (temp) {
        if (temp->data == 0) cnt0++;
        else if (temp->data == 1) cnt1++;
        else cnt2++;
        
        temp = temp->next;
    }
    
    temp = head;
    
    while (temp) {
        while (cnt0 > 0) {
            temp->data = 0;
            temp = temp->next;
            cnt0--;
        }
        while (cnt1 > 0) {
            temp->data = 1;
            temp = temp->next;
            cnt1--;
        }
        while (cnt2 > 0) {
            temp->data = 2;
            temp = temp->next;
            cnt2--;
        }
    }
    
    return head;
}

// Approach 2: Using separate lists
// Idea: Create three separate lists for 0s, 1s, and 2s, then concatenate them.
// Time Complexity: O(n) - We traverse the list once.
// Space Complexity: O(1) - No extra space is used except for pointers.
Node* segregateSeparateLists(Node* head) {
    Node* d0 = new Node(-1);
    Node* d1 = new Node(-1);
    Node* d2 = new Node(-1);

    Node* d_0 = d0;
    Node* d_1 = d1;
    Node* d_2 = d2;

    Node* temp = head;

    while (temp) {
        if (temp->data == 0) {
            d_0->next = temp;
            d_0 = temp;
        } else if (temp->data == 1) {
            d_1->next = temp;
            d_1 = temp;
        } else {
            d_2->next = temp;
            d_2 = temp;
        }

        temp = temp->next;
    }

    d_0->next = (d1->next) ? d1->next : d2->next;
    d_1->next = d2->next;
    d_2->next = NULL;

    head = d0->next;

    delete d0;
    delete d1;
    delete d2;

    return head;
}

// Function to print the linked list
void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example:
    // Given linked list: 1 -> 2 -> 0 -> 1 -> 2 -> 0 -> 1
    // After segregation: 0 -> 0 -> 1 -> 1 -> 1 -> 2 -> 2

    // Creating the linked list
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);

    cout << "Original list: ";
    printList(head);

    // Using counting elements approach
    Node* resultCount = segregateCount(head);
    cout << "Segregated list (Counting elements): ";
    printList(resultCount);

    // Resetting the linked list for the second approach
    head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(0);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(2);
    head->next->next->next->next->next = new Node(0);
    head->next->next->next->next->next->next = new Node(1);

    // Using separate lists approach
    Node* resultSeparateLists = segregateSeparateLists(head);
    cout << "Segregated list (Separate lists): ";
    printList(resultSeparateLists);

    return 0;
}