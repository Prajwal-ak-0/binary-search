#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach: Two-pointer technique
// Idea: Use two pointers to traverse both lists. When one pointer reaches the end, redirect it to the head of the other list. If the lists intersect, the pointers will meet at the intersection node after at most 2 passes.
// Time Complexity: O(m + n) - We traverse both lists at most twice.
// Space Complexity: O(1) - No extra space is used except for pointers.
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* a = headA;
    ListNode* b = headB;

    while (a != b) {
        a = a == NULL ? headB : a->next;
        b = b == NULL ? headA : b->next;
    }

    return a;
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
    // List A: 1 -> 9 -> 1 -> 2 -> 4
    // List B: 3 -> 2 -> 4
    // Intersection at node with value 2

    // Creating the linked lists
    ListNode* intersect = new ListNode(2);
    intersect->next = new ListNode(4);

    ListNode* headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = intersect;

    ListNode* headB = new ListNode(3);
    headB->next = intersect;

    cout << "List A: ";
    printList(headA);

    cout << "List B: ";
    printList(headB);

    // Finding the intersection node
    ListNode* intersection = getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection at node with value: " << intersection->val << endl;
    } else {
        cout << "No intersection" << endl;
    }

    return 0;
}