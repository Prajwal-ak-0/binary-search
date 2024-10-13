#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Reverse nodes in k-group in a linked list.

Approach:
1. Use a dummy node to simplify edge cases.
2. Traverse the list and reverse every k nodes.
3. Use a helper function to reverse k nodes.
4. Adjust the pointers to connect the reversed groups.
5. Return the new head of the list.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

ListNode* reverseKNodes(ListNode* head, int k) {
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* next = NULL;

    while (k > 0 && curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        k--;
    }

    return prev;
}

ListNode* reverseKGroup(ListNode* head, int k) {
    if (!head || k <= 1) {
        return head;
    }

    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* prev_end = dummy;

    while (true) {
        ListNode* curr = prev_end->next;
        ListNode* next_start = curr;

        for (int i = 0; i < k; i++) {
            if (!next_start) {
                return dummy->next;
            }
            next_start = next_start->next;
        }

        ListNode* new_end = prev_end->next;
        prev_end->next = reverseKNodes(curr, k);
        new_end->next = next_start;
        prev_end = new_end;
    }
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

    int k = 3;
    ListNode* reversedHead = reverseKGroup(head, k);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4 -> 5
    // Reverse in groups of 3
    // The reversed list should be: 3 -> 2 -> 1 -> 4 -> 5
    // Expected output: 3 2 1 4 5

    cout << "List after reversing in groups of " << k << ": ";
    printList(reversedHead);

    return 0;
}