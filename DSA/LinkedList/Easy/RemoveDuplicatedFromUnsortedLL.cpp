#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
};

/*
Idea: Remove duplicates from an unsorted linked list.

Approach:
1. Use an unordered map to keep track of visited nodes.
2. Traverse the linked list.
3. If the current node's data is already in the map, delete the current node.
4. If the current node's data is not in the map, add it to the map and move to the next node.

Time Complexity: O(n) - We traverse the entire list once.
Space Complexity: O(n) - We use an unordered map to store the visited nodes.
*/

Node* removeDuplicates(Node* head) {
    if (!head) return head;

    unordered_map<int, bool> vis;
    Node* curr = head;
    Node* prev = NULL;

    while (curr) {
        if (vis[curr->data]) {
            prev->next = curr->next;
            delete curr;
        } else {
            vis[curr->data] = true;
            prev = curr;
        }
        curr = prev->next;
    }

    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating an unsorted linked list with duplicates: 1 -> 2 -> 3 -> 2 -> 4 -> 3 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(2);
    head->next->next->next->next = new Node(4);
    head->next->next->next->next->next = new Node(3);
    head->next->next->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    head = removeDuplicates(head);

    // Test case explanation:
    // Unsorted linked list with duplicates: 1 -> 2 -> 3 -> 2 -> 4 -> 3 -> 5
    // After removing duplicates, the list should be: 1 -> 2 -> 3 -> 4 -> 5
    // Expected output: 1 2 3 4 5

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}