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
        // Task: The task is to build a binary tree from its inorder and postorder traversal.
        // Approach: We use a recursive approach where we find the root in the inorder traversal and then build the left and right subtrees.
        // Time Complexity: O(n^2), where n is the number of nodes in the tree. This is because for each node we are searching it in the inorder traversal.
        // Space Complexity: O(h), where h is the height of the tree. This is the maximum amount of space required by the call stack.

        TreeNode* build(vector<int>& inorder, int inSt, int inEd, vector<int> &postorder, int poSt, int poEd){
            if(inSt > inEd || poSt > poEd) return NULL;

            int rootVal = postorder[poEd];

            TreeNode* root = new TreeNode(rootVal);

            int rootIndex = find(inorder.begin() + inSt, inorder.begin() + inEd + 1, rootVal) - inorder.begin();

            int leftTreeSize = rootIndex - inSt;

            root->left = build(inorder, inSt, rootIndex - 1, postorder, poSt , poSt + leftTreeSize - 1 );
            root->right = build(inorder, rootIndex+1, inEd, postorder, poSt + leftTreeSize, poEd - 1);

            return root;
        }

        TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
            if(inorder.empty() || postorder.empty()) return NULL;

            return build(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
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
        // Test Case: The inorder traversal is [9,3,15,20,7] and the postorder traversal is [9,15,7,20,3]
        // The tree is [3,9,20,null,null,15,7]
        Solution solution;
        vector<int> inorder = {9,3,15,20,7};
        vector<int> postorder = {9,15,7,20,3};
        TreeNode* root = solution.buildTree(inorder, postorder);
        // Print the tree in inorder traversal
        printInOrder(root);
        cout << endl;

        return 0;
    }