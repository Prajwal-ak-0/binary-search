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
    // Task: The task is to invert a binary tree.
    // Approach: We use a recursive approach where we swap the left and right subtrees of each node.
    // Time Complexity: O(n), where n is the number of nodes in the tree. This is because we visit each node once.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }

        TreeNode* temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);

        return root;
    }

    void printPreOrder(TreeNode* node) {
        if (node == NULL) {
            return;
        }
        cout << node->val << " ";
        printPreOrder(node->left);
        printPreOrder(node->right);
    }
};

int main() {
    // Test Case: The tree is [4,2,7,1,3,6,9]
    // The inverted tree is [4,7,2,9,6,3,1]
    Solution solution;
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(7);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);
    TreeNode* invertedRoot = solution.invertTree(root);
    // Print the inverted tree in pre-order traversal
    solution.printPreOrder(invertedRoot);
    cout << endl;

    return 0;
}