#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Task: The task is to check if two binary trees are the same.
    // Approach: We use a recursive approach where we check if the current nodes are the same and if the left and right subtrees are the same.
    // Time Complexity: O(n), where n is the number of nodes in the tree. This is because we visit each node once.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL && q==NULL) return 1;

        if(p==NULL || q==NULL) return 0;

        if(p->val == q->val){
            return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
        }
        else{
            return 0;
        }
    }
};

int main() {
    // Test Case: The trees are [1,2,3] and [1,2,3]
    // The trees are the same
    Solution solution;
    TreeNode* p = new TreeNode(1);
    p->left = new TreeNode(2);
    p->right = new TreeNode(3);
    TreeNode* q = new TreeNode(1);
    q->left = new TreeNode(2);
    q->right = new TreeNode(3);
    bool isSame = solution.isSameTree(p, q);
    cout << "The trees are " << (isSame ? "the same" : "not the same") << endl;

    return 0;
}