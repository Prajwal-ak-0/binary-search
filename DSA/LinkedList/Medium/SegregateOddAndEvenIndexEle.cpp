#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// Approach 1: In-place rearrangement
// Idea: Rearrange the nodes in-place by maintaining separate pointers for odd and even indexed nodes.
// Approach: Use two pointers to traverse the list, one for odd indexed nodes and one for even indexed nodes. Rearrange the pointers accordingly.
// Time Complexity: O(n) - We traverse the list once.
// Space Complexity: O(1) - No extra space is used except for pointers.
ListNode* oddEvenListInPlace(ListNode* head) {
    if (!head || !head->next) return head;

    ListNode* o = head;
    ListNode* e = o->next;
    ListNode* e_head = e;

    while (e && e->next) {
        o->next = e->next;
        o = e->next;
        e->next = o->next;
        e = o->next;
    }

    o->next = e_head;

    return head;
}

// Approach 2: Using vectors
// Idea: Use vectors to store odd and even indexed nodes separately and then link them together.
// Approach: Traverse the list and store nodes in two separate vectors for odd and even indexed nodes. Then link the nodes in the vectors.
// Time Complexity: O(n) - We traverse the list once and then link the nodes.
// Space Complexity: O(n) - Extra space is used for storing nodes in vectors.
ListNode* oddEvenListUsingVectors(ListNode* head) {
    vector<ListNode*> o;
    vector<ListNode*> e;

    ListNode* t = head;
    int cnt = 0;

    while (t != NULL) {
        cnt++;
        if (cnt % 2 == 0) {
            e.push_back(t);
        } else {
            o.push_back(t);
        }
        t = t->next;
    }

    for (size_t i = 0; i < o.size(); ++i) {
        if (i < o.size() - 1) {
            o[i]->next = o[i + 1];
        } else {
            o[i]->next = (e.empty()) ? NULL : e[0];
        }
    }

    for (size_t j = 0; j < e.size(); ++j) {
        if (j < e.size() - 1) {
            e[j]->next = e[j + 1];
        } else {
            e[j]->next = NULL;
        }
    }

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
    // After rearranging: 1 -> 3 -> 5 -> 2 -> 4

    // Creating the linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    // Using in-place rearrangement approach
    ListNode* resultInPlace = oddEvenListInPlace(head);
    cout << "Rearranged list (In-place): ";
    printList(resultInPlace);

    // Resetting the linked list for the second approach
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Using vectors approach
    ListNode* resultUsingVectors = oddEvenListUsingVectors(head);
    cout << "Rearranged list (Using vectors): ";
    printList(resultUsingVectors);

    return 0;
}