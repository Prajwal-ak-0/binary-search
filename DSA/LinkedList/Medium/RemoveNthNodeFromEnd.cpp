#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach: Two-pointer technique
// Idea: Use two pointers to find the nth node from the end of the list.
// Approach: Move the first pointer `n` steps ahead, then move both pointers until the first pointer reaches the end. The second pointer will be at the (n+1)th node from the end. Adjust the pointers to remove the nth node.
// Time Complexity: O(n) - We traverse the list once.
// Space Complexity: O(1) - No extra space is used except for pointers.
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* f = head;
    ListNode* s = head;

    for (int i = 0; i < n; i++) {
        f = f->next;
    }

    if (!f) return head->next;

    while (f->next) {
        f = f->next;
        s = s->next;
    }

    ListNode* d = s->next;
    s->next = s->next->next;
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
    // Given linked list: 1 -> 2 -> 3 -> 4 -> 5, n = 2
    // After removing the 2nd node from the end: 1 -> 2 -> 3 -> 5

    // Creating the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Removing the 2nd node from the end
    int n = 2;
    ListNode* result = removeNthFromEnd(head, n);
    cout << "List after removing " << n << "th node from the end: ";
    printList(result);

    return 0;
}