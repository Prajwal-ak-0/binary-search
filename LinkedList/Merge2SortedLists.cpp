    #include <iostream>
    using namespace std;

    class ListNode {
    public:
        int val;
        ListNode *next;

        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}

        ListNode* mergeTwoListsMethod1(ListNode* list1, ListNode* list2) {
            ListNode* prev = NULL;
            ListNode* res = NULL;
            if (list1 == nullptr) {
                return list2;
            }
            if (list2 == nullptr) {
                return list1;
            }

            if (list1 != NULL && list2 != NULL) {
                if (list1->val <= list2->val) {
                    prev = list1;
                    res = list1;
                    list1 = list1->next;
                } else {
                    prev = list2;
                    res = list2;
                    list2 = list2->next;
                }
            }

            while (list1 != NULL && list2 != NULL) {
                if (list1->val <= list2->val) {
                    prev->next = list1;
                    prev = list1;
                    list1 = list1->next;
                } else {
                    prev->next = list2;
                    prev = list2;
                    list2 = list2->next;
                }
            }
            
            if(prev != NULL && list1 != NULL){
                prev->next = list1;
            }

            if(prev != NULL && list2 != NULL){
                prev->next = list2;
            }

            return res;
        }

        ListNode* mergeTwoListsMethod2(ListNode* list1, ListNode* list2) {
            ListNode dummy;
            ListNode* tail = &dummy;

            while(list1 != NULL && list2 != NULL){
                if(list1->val <= list2->val){
                    tail->next = list1;
                    list1 = list1->next;
                }
                else{
                    tail->next = list2;
                    list2 = list2->next;
                }
                tail = tail->next;
            }

            tail->next = (list1 != nullptr) ? list1 : list2;

            return dummy.next;
        }
    };

    int main() {
        // Test Case:
        // Input: list1 = [1,2,4], list2 = [1,3,4]
        // Output: [1,1,2,3,4,4]
        ListNode* list1 = new ListNode(1);
        list1->next = new ListNode(2);
        list1->next->next = new ListNode(4);

        ListNode* list2 = new ListNode(1);
        list2->next = new ListNode(3);
        list2->next->next = new ListNode(4);

        ListNode* result1 = list1->mergeTwoListsMethod1(list1, list2);
        ListNode* result2 = list1->mergeTwoListsMethod2(list1, list2);

        // Print the results
        cout << "The merged list using Method 1 is: ";
        while (result1 != NULL) {
            cout << result1->val << " ";
            result1 = result1->next;
        }
        cout << endl;

        cout << "The merged list using Method 2 is: ";
        while (result2 != NULL) {
            cout << result2->val << " ";
            result2 = result2->next;
        }
        cout << endl;

        return 0;
    }