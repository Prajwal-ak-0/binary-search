#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    // Task: The task is to remove all duplicates from a sorted linked list.
    // Approach: We use a dummy node to handle the edge case where the head is a duplicate. We then iterate through the list, and whenever we encounter a duplicate, we skip all nodes with the same value.
    // Time Complexity: O(n), where n is the number of nodes in the list. This is because we are iterating through the list once.
    // Space Complexity: O(1), we are not using any extra space that scales with input size.

    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *prev = dummy;

        while (head != NULL)
        {
            if (head->next != NULL && head->val == head->next->val)
            {
                while (head->next != NULL && head->val == head->next->val)
                {
                    head = head->next;
                }
                prev->next = head->next;
            }
            else
            {
                prev = prev->next;
            }
            head = head->next;
        }

        return dummy->next;
    }
};

int main()
{
    // Test Case: The list is 1->1->2->3->3
    // The list after removing duplicates should be 1->2->3
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(3);
    ListNode *result = solution.deleteDuplicates(head);
    cout << "List after removing duplicates: ";
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}
