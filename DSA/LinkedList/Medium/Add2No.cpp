#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Add two numbers represented by linked lists.

Approach:
1. Initialize a dummy node to build the result list.
2. Traverse both linked lists and add corresponding digits.
3. Keep track of the carry and add it to the next digit.
4. Create new nodes for the result list and link them.
5. Return the next node of the dummy node as the head of the result list.

Time Complexity: O(max(m, n)) - We traverse both lists once.
Space Complexity: O(max(m, n)) - The result list can have at most max(m, n) + 1 nodes.
*/

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* d = new ListNode(-1);
    ListNode* temp = d;

    int c = 0;

    while (l1 || l2 || c) {
        int s = c;

        if (l1) {
            s += l1->val;
            l1 = l1->next;
        }

        if (l2) {
            s += l2->val;
            l2 = l2->next;
        }

        ListNode* new_node = new ListNode(s % 10);
        temp->next = new_node;
        temp = new_node;

        c = s / 10;
    }

    return d->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating first linked list: 2 -> 4 -> 3 (represents number 342)
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Creating second linked list: 5 -> 6 -> 4 (represents number 465)
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    ListNode* result = addTwoNumbers(l1, l2);

    // Test case explanation:
    // First linked list: 2 -> 4 -> 3 (represents number 342)
    // Second linked list: 5 -> 6 -> 4 (represents number 465)
    // The sum is 342 + 465 = 807
    // The resulting linked list should be: 7 -> 0 -> 8
    // Expected output: 7 0 8

    cout << "The resulting linked list is: ";
    printList(result);

    return 0;
}