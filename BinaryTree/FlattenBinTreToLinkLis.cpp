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
    // Task: The task is to flatten a binary tree to a linked list in-place.
    // Approach: We use a recursive approach where we flatten the left and right subtrees and then append the left subtree to the root and the right subtree to the end of the new left subtree.
    // Time Complexity: O(n), where n is the number of nodes in the tree. This is because we are visiting each node once.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    void flatten(TreeNode* root) {
        if (root == NULL)
            return;

        flatten(root->left);
        flatten(root->right);

        TreeNode* rightSubTree = root->right;

        root->right = root->left;
        root->left = NULL;

        TreeNode* temp = root->right;

        while (temp != NULL && temp->right != NULL) {
            temp = temp->right;
        }

        if (temp != NULL) {
            temp->right = rightSubTree;
        } else {
            root->right = rightSubTree;
        }
    }
};

void printTree(TreeNode* root) {
    while (root != NULL) {
        cout << root->val << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    // Test Case: The tree is [1,2,5,3,4,null,6]
    // After flattening, the tree should be [1,null,2,null,3,null,4,null,5,null,6]
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(5, nullptr, new TreeNode(6));
    solution.flatten(root);
    printTree(root);  // Output: 1 2 3 4 5 6

    return 0;
}