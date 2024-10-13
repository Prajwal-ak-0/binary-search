#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int x) : data(x), next(NULL), prev(NULL) {}
};

/*
Idea: Find all pairs of nodes in a doubly linked list that sum up to a given target.

Approach:
1. Use two pointers: left starting from the head and right starting from the tail.
2. Traverse the list with the two pointers.
3. If the sum of the values of the nodes pointed to by the two pointers equals the target, add the pair to the result.
4. If the sum is less than the target, move the left pointer to the next node.
5. If the sum is greater than the target, move the right pointer to the previous node.
6. Stop when the left pointer meets or crosses the right pointer.

Time Complexity: O(n) - We traverse the list with two pointers.
Space Complexity: O(1) - Only a few extra variables are used.
*/

vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target) {
    vector<pair<int, int>> result;

    if (!head) return result;

    Node *left = head;
    Node *right = head;

    while (right->next) {
        right = right->next;
    }

    while (left != right && left->prev != right) {
        int sum = left->data + right->data;

        if (sum == target) {
            result.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        } 
        else if (sum < target) {
            left = left->next;
        } 
        else {
            right = right->prev;
        }
    }

    return result;
}

void printPairs(const vector<pair<int, int>>& pairs) {
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << endl;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->prev = head->next->next->next;

    cout << "Original list: ";
    printList(head);

    int target = 5;
    vector<pair<int, int>> result = findPairsWithGivenSum(head, target);

    // Test case explanation:
    // Doubly linked list: 1 <-> 2 <-> 3 <-> 4 <-> 5
    // Target sum: 5
    // Pairs with sum 5: (1, 4), (2, 3)
    // Expected output: (1, 4) (2, 3)

    cout << "Pairs with sum " << target << ": ";
    printPairs(result);

    return 0;
}