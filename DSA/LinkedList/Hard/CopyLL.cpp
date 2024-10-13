#include <iostream>
#include <unordered_map>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node* random;
    Node(int x) : val(x), next(NULL), random(NULL) {}
};

/*
Idea: Create a deep copy of a linked list with random pointers.

Approach:
1. Use an unordered map to store the mapping between original nodes and their copies.
2. Traverse the original list and create a new node for each original node, storing the mapping in the unordered map.
3. Traverse the original list again and set the next and random pointers for each copied node using the map.
4. Return the head of the copied list.

Time Complexity: O(n) - We traverse the list twice.
Space Complexity: O(n) - We use an unordered map to store the mapping.
*/

Node* copyRandomList(Node* head) {
    Node* temp = head;
    unordered_map<Node*, Node*> mp;

    while (temp) {
        Node* new_node = new Node(temp->val);
        mp[temp] = new_node;
        temp = temp->next;
    }

    temp = head;

    while (temp) {
        mp[temp]->next = mp[temp->next];
        mp[temp]->random = mp[temp->random];
        temp = temp->next;
    }

    return mp[head];
}

void printList(Node* head) {
    while (head != NULL) {
        cout << "Node value: " << head->val;
        if (head->random) {
            cout << ", Random points to: " << head->random->val;
        } else {
            cout << ", Random points to: NULL";
        }
        cout << endl;
        head = head->next;
    }
}

int main() {
    // Creating a linked list with random pointers:
    // 1 -> 2 -> 3 -> 4 -> 5
    // Random pointers: 1->3, 2->1, 3->5, 4->3, 5->2
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->random = head->next->next; // 1->3
    head->next->random = head; // 2->1
    head->next->next->random = head->next->next->next->next; // 3->5
    head->next->next->next->random = head->next->next; // 4->3
    head->next->next->next->next->random = head->next; // 5->2

    cout << "Original list:" << endl;
    printList(head);

    Node* copiedHead = copyRandomList(head);

    // Test case explanation:
    // Original linked list: 1 -> 2 -> 3 -> 4 -> 5
    // Random pointers: 1->3, 2->1, 3->5, 4->3, 5->2
    // The copied list should have the same structure and random pointers.
    // Expected output: Same as the original list.

    cout << "Copied list:" << endl;
    printList(copiedHead);

    return 0;
}