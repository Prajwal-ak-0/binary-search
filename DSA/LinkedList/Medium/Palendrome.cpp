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

ListNode* rev(ListNode* head) {
    ListNode* p = NULL;
    ListNode* c = head;
    ListNode* f = head;

    while (c != NULL) {
        f = c->next; 
        c->next = p; 
        p = c;     
        c = f;     
    }

    return p;
}

/*
Idea: Find the middle node of a linked list.

Approach:
1. Use two pointers: fast (f) and slow (s).
2. Move the fast pointer two steps and the slow pointer one step at a time.
3. When the fast pointer reaches the end, the slow pointer will be at the middle.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

ListNode* mid(ListNode* head) {
    ListNode* f = head;
    ListNode* s = head;

    while (f->next != NULL && f->next->next != NULL) {
        s = s->next;
        f = f->next->next;
    }

    return s;
}

/*
Idea: Check if a linked list is a palindrome.

Approach:
1. Find the middle of the list.
2. Reverse the second half of the list.
3. Compare the first half with the reversed second half.
4. If all corresponding nodes are equal, the list is a palindrome.

Time Complexity: O(n) - We traverse the entire list a few times.
Space Complexity: O(1) - Only a few extra variables are used.
*/

bool isPalindrome(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }

    ListNode* m = mid(head);
    ListNode* rev_h = rev(m->next);

    while (rev_h != NULL) {
        if (head->val != rev_h->val)
            return false;
        head = head->next;
        rev_h = rev_h->next;
    }

    return true;
}

int main() {
    // Creating a linked list: 1 -> 2 -> 2 -> 1
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);

    bool result = isPalindrome(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 2 -> 1
    // The list is a palindrome.
    // Expected output: true

    cout << "The linked list is " << (result ? "a palindrome." : "not a palindrome.") << endl;

    // Creating a linked list: 1 -> 2 -> 3 -> 4
    head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    result = isPalindrome(head);

    // Test case explanation:
    // Linked list: 1 -> 2 -> 3 -> 4
    // The list is not a palindrome.
    // Expected output: false

    cout << "The linked list is " << (result ? "a palindrome." : "not a palindrome.") << endl;

    return 0;
}