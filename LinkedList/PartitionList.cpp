#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 1).  Initialize two dummy nodes, less_head and greater_head, to represent the heads of the partitions containing nodes less than x and nodes greater than or equal to x, respectively.

// 2). Traverse the original linked list.

//      2.1). If the current node's value is less than x, append it to the partition of nodes less than x.
//      2.2). If the current node's value is greater than or equal to x, append it to the partition of nodes greater than or equal to x.
// 3). Once you've traversed the entire list, link the tail of the partition containing nodes less than x to the head of the partition containing nodes greater than or equal to x.

// 4). Return the head of the partition containing nodes less than x, which is less_head->next.

class Solution
{
public:
    // Task: The task is to partition a linked list around a value x, such that all nodes less than x come before all nodes greater than or equal to x.
    // Approach: We create two separate linked lists: one for elements less than x, and one for elements greater than or equal to x. We then concatenate these two lists.
    // Time Complexity: O(n), where n is the number of nodes in the list. This is because we are iterating through the list once.
    // Space Complexity: O(n), for the new list. In the worst case (when all nodes are less than x or all nodes are greater than or equal to x), we will create a new list with all nodes.

    ListNode *partition(ListNode *head, int x)
    {
        ListNode *leftHead = new ListNode(0);
        ListNode *rightHead = new ListNode(0);

        ListNode *tail1 = leftHead;
        ListNode *tail2 = rightHead;

        ListNode *curr = head;

        while (curr)
        {
            ListNode *newNode = new ListNode(curr->val);
            if (curr->val < x)
            {
                tail1->next = newNode;
                tail1 = newNode;
            }
            else
            {
                tail2->next = newNode;
                tail2 = newNode;
            }
            curr = curr->next;
        }

        tail1->next = rightHead->next;

        ListNode *result = leftHead->next;

        delete leftHead;
        delete rightHead;

        return result;
    }
};

int main()
{
    // Test Case: The list is 1->4->3->2->5->2 and x is 3
    // The partitioned list should be 1->2->2->4->3->5
    Solution solution;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(4);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(2);
    ListNode *result = solution.partition(head, 3);
    cout << "Partitioned List: ";
    while (result)
    {
        cout << result->val << " ";
        result = result->next;
    }
    cout << endl;

    return 0;
}