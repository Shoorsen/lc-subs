/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lower;
        TreeNode* upper;
        if (p->val < q->val) {
            lower = p;
            upper = q;
        } else {
            lower = q;
            upper = p;
        }

        while (root != nullptr) {
            if (lower->val < root->val && upper->val > root->val) {
                return root;
            }
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            } 
            else if (p->val > root->val && q->val > root->val) {
                root = root->right;
            } else if (root->val == p->val) {
                return root;
            } else if (root->val == q->val) {
                return root;
            }
        }
        return root;
    }
};