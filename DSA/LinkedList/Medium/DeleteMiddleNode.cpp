#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach: Two-pointer technique
// Idea: Use two pointers to find the middle node of the list and delete it.
// Approach: Move the first pointer `f` two steps at a time and the second pointer `s` one step at a time. When `f` reaches the end, `s` will be at the middle. Adjust the pointers to remove the middle node.
// Time Complexity: O(n) - We traverse the list once.
// Space Complexity: O(1) - No extra space is used except for pointers.
ListNode* deleteMiddle(ListNode* head) {
    if (head->next == NULL) return NULL;

    ListNode* f = head;
    ListNode* p = NULL;
    ListNode* s = head;

    while (f && f->next) {
        f = f->next->next;
        p = s;
        s = s->next;
    }

    ListNode* d = s;
    p->next = s->next;
    delete d;

    return head;
}

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Example:
    // Given linked list: 1 -> 2 -> 3 -> 4 -> 5
    // After deleting the middle node: 1 -> 2 -> 4 -> 5

    // Creating the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Deleting the middle node
    ListNode* result = deleteMiddle(head);
    cout << "List after deleting the middle node: ";
    printList(result);

    return 0;
}