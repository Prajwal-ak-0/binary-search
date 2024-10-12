#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Delete a node (except the tail) in a singly linked list, given only access to that node.

Approach:
1. Copy the value of the next node to the current node.
2. Delete the next node by adjusting the pointers.

Time Complexity: O(1) - We perform a constant amount of work.
Space Complexity: O(1) - Only a few extra variables are used.
*/

void deleteNode(ListNode* node) {
    node->val = node->next->val;
    ListNode* temp = node->next;
    node->next = temp->next;
    delete temp;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 3 -> 4 -> 5
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Deleting node with value 3
    deleteNode(head->next->next);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // After deleting node with value 3, the list should be: 1 -> 2 -> 4 -> 5
    // Expected output: 1 2 4 5

    cout << "List after deleting node with value 3: ";
    printList(head);

    return 0;
}