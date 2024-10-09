#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach: Merge Sort for Linked List
// Idea: Use merge sort to sort the linked list. The list is divided into two halves, sorted individually, and then merged.
// Time Complexity: O(n log n) - Each split takes O(log n) and merging takes O(n).
// Space Complexity: O(log n) - Recursion stack space.

ListNode* mergeTwoSortedLL(ListNode* h1, ListNode* h2) {
    ListNode* dummyListNode = new ListNode(-1);
    ListNode* temp = dummyListNode;

    while (h1 != NULL && h2 != NULL) {
        if (h1->val <= h2->val) {
            temp->next = h1;
            h1 = h1->next;
        } else {
            temp->next = h2;
            h2 = h2->next;
        }
        temp = temp->next;
    }

    if (h1 != NULL) {
        temp->next = h1;
    } else {
        temp->next = h2;
    }

    return dummyListNode->next;
}

ListNode* findMid(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* slow = head;
    ListNode* fast = head->next;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

ListNode* sortList(ListNode* head) {
    if (head == NULL || head->next == NULL)
        return head;

    ListNode* m = findMid(head);

    ListNode* r = m->next;
    m->next = NULL;
    ListNode* l = head;

    ListNode* left = sortList(l);
    ListNode* right = sortList(r);

    return mergeTwoSortedLL(left, right);
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
    // Given linked list: 4 -> 2 -> 1 -> 3
    // After sorting: 1 -> 2 -> 3 -> 4

    // Creating the linked list
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);

    cout << "Original list: ";
    printList(head);

    // Sorting the linked list
    ListNode* sortedHead = sortList(head);
    cout << "Sorted list: ";
    printList(sortedHead);

    return 0;
}