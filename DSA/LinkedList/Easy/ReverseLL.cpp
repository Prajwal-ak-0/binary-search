#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
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

ListNode* reverseList(ListNode* head) {
    ListNode* p = NULL;
    ListNode* c = head;
    ListNode* f = head;

    while (f != NULL) {
        f = c->next;
        c->next = p;
        p = c;
        c = f;
    }

    return p;
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

    ListNode* reversedHead = reverseList(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // The reversed list is: 5 -> 4 -> 3 -> 2 -> 1
    // Expected output: 5 4 3 2 1

    cout << "Reversed list: ";
    printList(reversedHead);

    return 0;
}