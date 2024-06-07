#include <iostream>
#include <vector>
#include <algorithm>

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
    // Task: The task is to build a binary tree from its inorder and preorder traversal.
    // Approach: We use a recursive approach where we find the root in the inorder traversal and then build the left and right subtrees.
    // Time Complexity: O(n^2), where n is the number of nodes in the tree. This is because for each node we are searching it in the inorder traversal.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                        vector<int>& inorder, int inStart, int inEnd) {
        if (preStart > preEnd || inStart > inEnd)
            return NULL;

        int rootValue = preorder[preStart];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndex = find(inorder.begin() + inStart,
                             inorder.begin() + inEnd + 1, rootValue) -
                        inorder.begin();

        int leftTreeSize = rootIndex - inStart;

        root->left = buildTree(preorder, preStart + 1, preStart + leftTreeSize,
                               inorder, inStart, rootIndex - 1);
        root->right = buildTree(preorder, preStart + leftTreeSize + 1, preEnd,
                                inorder, rootIndex + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.empty() || inorder.empty())
            return NULL;

        return buildTree(preorder, 0, preorder.size() - 1, inorder, 0,
                         inorder.size() - 1);
    }
};

void printInOrder(TreeNode* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    cout << node->val << " ";
    printInOrder(node->right);
}

int main() {
    // Test Case: The inorder traversal is [9,3,15,20,7] and the preorder traversal is [3,9,20,15,7]
    // The tree is [3,9,20,null,null,15,7]
    Solution solution;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> preorder = {3,9,20,15,7};
    TreeNode* root = solution.buildTree(preorder, inorder);
    // Print the tree in inorder traversal
    printInOrder(root);
    cout << endl;

    return 0;
}