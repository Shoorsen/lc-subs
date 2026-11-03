/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode* root, int& dia) {
        if(root == nullptr) {
            return 0;
        }
        int leftHeight = maxDepth(root->left, dia);
        int rightHeight = maxDepth(root->right, dia);
        dia = std::max(dia, leftHeight+rightHeight);
        return 1 + std::max(leftHeight, rightHeight);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int diameter = 0;
        int m = maxDepth(root, diameter);
        return diameter;
    }
};