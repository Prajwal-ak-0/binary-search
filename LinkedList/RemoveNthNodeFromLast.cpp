    #include <iostream>

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Idea: The idea is to remove the nth node from the end of the list.
        // Approach: We use two pointers, fast and slow. We first move the fast pointer n nodes ahead.
        // Then we move both pointers one step at a time. When the fast pointer reaches the end, the slow pointer will be at the nth node from the end.
        // We then remove the nth node.
        // Time Complexity: O(n), where n is the length of the list.
        // Space Complexity: O(1), as we are not using any extra space proportional to the input.

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode *fast = dummy;
        ListNode *slow = dummy;

        for(int i=0;i<n+1;i++){
            fast = fast->next;
        }

        while(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }

    int main() {
        // Test Case: The linked list is 1->2->3->4->5, n = 2
        // After removing the 2nd node from the end, the list becomes 1->2->3->5.
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* result = removeNthFromEnd(head, 2);

        while(result != NULL) {
            std::cout << result->val << " ";
            result = result->next;
        }

        return 0;
    }