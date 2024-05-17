    #include <iostream>

    // Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode(int x) : val(x), next(NULL) {}
    };

    ListNode* reverseKGroup(ListNode* head, int k) {
        // Idea: The idea is to reverse every k nodes of the linked list.
        // Approach: We first check if there are at least k nodes to reverse. If not, we return the head.
        // If there are k nodes, we reverse them and recursively call the function for the next k nodes.
        // Time Complexity: O(n), where n is the length of the list.
        // Space Complexity: O(n/k), for the recursive call stack.

        if(head == NULL || head->next == NULL || k==1){
            return head;
        }

        ListNode* temp = head;
        for(int i=0;i<k;i++){
            if(temp == NULL) {
                return head;
            }
            temp = temp->next;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* forw = NULL;
        int i = 0;
        while(curr != NULL && i < k){
            forw = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forw;
            i++;
        }

        if(curr!=NULL){
            head->next = reverseKGroup(curr, k);
        }

        return prev;
    }

    int main() {
        // Test Case: The linked list is 1->2->3->4->5, k = 2
        // After reversing every 2 nodes, the list becomes 2->1->4->3->5.
        ListNode* head = new ListNode(1);
        head->next = new ListNode(2);
        head->next->next = new ListNode(3);
        head->next->next->next = new ListNode(4);
        head->next->next->next->next = new ListNode(5);

        ListNode* result = reverseKGroup(head, 2);

        while(result != NULL) {
            std::cout << result->val << " ";
            result = result->next;
        }

        return 0;
    }