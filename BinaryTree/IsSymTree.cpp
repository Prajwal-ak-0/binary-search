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
    // Task: The task is to check if a binary tree is symmetric.
    // Approach: We use a recursive approach where we check if the left subtree is a mirror reflection of the right subtree.
    // Time Complexity: O(n), where n is the number of nodes in the tree. This is because we are visiting each node once.
    // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

    bool checkMirror(TreeNode* t1, TreeNode* t2){
        if(t1 == NULL && t2 == NULL) return true;
        if(t1 == NULL || t2 == NULL) return false;
        
        return (t1->val == t2->val) && checkMirror(t1->left, t2->right) && checkMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        return checkMirror(root, root);
    }
};

int main() {
    // Test Case: The tree is [1,2,2,3,4,4,3], which is symmetric
    Solution solution;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
    root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));
    bool isSym = solution.isSymmetric(root);
    cout << (isSym ? "True" : "False") << endl;  // Output: True

    return 0;
}