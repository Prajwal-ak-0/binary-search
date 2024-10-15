#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

/*
Idea: Merge two sorted linked lists into one sorted linked list.

Approach:
1. Use a dummy node to simplify edge cases.
2. Use two pointers to traverse the two lists.
3. Compare the values at the two pointers and append the smaller value to the merged list.
4. Move the pointer of the list from which the smaller value was taken.
5. Continue until one of the lists is exhausted.
6. Append the remaining elements of the non-exhausted list to the merged list.
7. Return the next node of the dummy node as the head of the merged list.

Time Complexity: O(n + m) - We traverse both lists once.
Space Complexity: O(1) - Only a few extra variables are used.
*/

ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    ListNode* dummy = new ListNode(-1); 
    ListNode* curr = dummy;
    ListNode* t1 = list1;
    ListNode* t2 = list2;
    
    while(t1 && t2){
        if(t1->val <= t2->val){
            curr->next = t1;
            t1 = t1->next;
        }else{
            curr->next = t2;
            t2 = t2->next;
        }
        curr = curr->next;
    }
    
    if(t1) curr->next = t1;
    if(t2) curr->next = t2;
    
    return dummy->next;
}

void printList(ListNode* head) {
    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating two sorted linked lists:
    // List 1: 1 -> 3 -> 5
    // List 2: 2 -> 4 -> 6
    ListNode* list1 = new ListNode(1);
    list1->next = new ListNode(3);
    list1->next->next = new ListNode(5);

    ListNode* list2 = new ListNode(2);
    list2->next = new ListNode(4);
    list2->next->next = new ListNode(6);

    cout << "List 1: ";
    printList(list1);

    cout << "List 2: ";
    printList(list2);

    ListNode* mergedList = mergeTwoLists(list1, list2);

    // Test case explanation:
    // List 1: 1 -> 3 -> 5
    // List 2: 2 -> 4 -> 6
    // After merging, the list should be: 1 -> 2 -> 3 -> 4 -> 5 -> 6
    // Expected output: 1 2 3 4 5 6

    cout << "Merged list: ";
    printList(mergedList);

    return 0;
}