#include <iostream>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode* head) {
    // Idea: Use two pointers, one moving at twice the speed of the other. If there is a cycle, they will meet.
    // Approach: Initialize two pointers at the head of the list. Move the slow pointer one step at a time and the fast pointer two steps at a time. If they meet, there is a cycle. If the fast pointer reaches the end of the list, there is no cycle.
    // Time Complexity: O(n), where n is the number of nodes in the list.
    // Space Complexity: O(1), as we are only using a constant amount of space.

    ListNode *fast = head, *slow = head;

    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = head->next;  

    if (hasCycle(head)) {
        cout << "Cycle detected.\n";
    } else {
        cout << "No cycle detected.\n";
    }

    return 0;
}