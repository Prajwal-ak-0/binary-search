#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    // Task: The task is to find the maximum depth of a binary tree.
    // Approach: We use a recursive approach where the depth of the tree is the maximum depth of its two subtrees plus one.
    // Time Complexity: O(n), where n is the number of nodes in the tree. This is because we visit each node once.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    int maxDepth(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main()
{
    // Test Case: The tree is [3,9,20,null,null,15,7]
    // The maximum depth of the tree is 3
    Solution solution;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    int depth = solution.maxDepth(root);
    cout << "The maximum depth of the tree is: " << depth << endl;

    return 0;
}