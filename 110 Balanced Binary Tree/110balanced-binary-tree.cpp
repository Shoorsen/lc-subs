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
    // std::unordered_map<TreeNode*, int> heights;
    // void fillHeights(TreeNode* root) {
    //     if (root == nullptr) {
    //         heights[root] = 0;
    //     }
    //     if (root->left == nullptr && root->right == nullptr) {
    //         heights[root] = 1;
    //         return;
    //     }
    //     fillHeights(root->left);
    //     fillHeights(root->right);
    //     heights[root] = std::max(heights[root->left], heights[root->right]) +1;
    // }

    int checkBalance(TreeNode* root, bool& passed) {
        if (root == NULL) {
            return 0;
        }
        if (root->left == nullptr && root->right == nullptr) {
            return 1;
        }
        int l = checkBalance(root->left, passed);
        int r = checkBalance(root->right, passed);
        int height = 1 + std::max(l, r);
        if (std::abs(l-r) >= 2) {
            passed = false;
        }
        return height;
    }

    bool isBalanced(TreeNode* root) {
        bool passed = true;
        checkBalance(root, passed);
        return passed;
    //     fillHeights(root);
    //     std::stack<TreeNode*> st;
    //     st.push(root);
    //     while (!st.empty()) {
    //         if (std::abs(heights[root->left] - heights[root->right]) >= 2) {
    //             return false;
    //         } else {
    //             st.push(root->left);
    //             st.push(root->right);
    //         }
    //     }
    //     return true;
    }
};