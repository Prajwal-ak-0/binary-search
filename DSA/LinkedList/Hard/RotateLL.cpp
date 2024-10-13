#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Rotate a linked list to the right by k places.

Approach:
1. Calculate the length of the linked list.
2. Compute the effective rotation needed using k % length.
3. If the effective rotation is zero, return the head.
4. Traverse the list to the point where the rotation should happen.
5. Adjust the pointers to rotate the list.
6. Return the new head of the rotated list.

Time Complexity: O(n) - We traverse the list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

int len(ListNode* head) {
    int l = 0;
    ListNode* t = head;

    while (t) {
        l++;
        t = t->next;
    }

    return l;
}

ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next || k <= 0) {
        return head;
    }

    int cnt = len(head);
    k = k % cnt;

    if (k == 0) {
        return head;
    }

    cnt = cnt - k;
    int i = 0;

    ListNode* curr = head;
    ListNode* prev = NULL;

    while (cnt--) {
        prev = curr;
        curr = curr->next;
    }

    ListNode* tail = curr;

    while (tail->next) {
        tail = tail->next;
    }

    prev->next = NULL;
    tail->next = head;

    return curr;
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

    int k = 2;
    ListNode* rotatedHead = rotateRight(head, k);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // Rotate right by 2 places
    // The rotated list should be: 4 -> 5 -> 1 -> 2 -> 3
    // Expected output: 4 5 1 2 3

    cout << "List after rotating right by " << k << " places: ";
    printList(rotatedHead);

    return 0;
}