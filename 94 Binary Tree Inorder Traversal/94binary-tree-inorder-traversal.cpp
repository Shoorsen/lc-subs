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
    vector<int> inorderTraversal(TreeNode* root) {
        std::stack<TreeNode*> st;
        std::vector<TreeNode*> ans;
        std::vector<int> answ;
        auto cur = root;
        while (true) {
            if (cur == nullptr) {
                if (!st.empty()) {
                    auto top = st.top();
                    st.pop();
                    ans.push_back(top);

                    if (top->right != nullptr) {
                        // st.push(top->right);
                        cur = top->right;
                    }
                } else {
                    break;
                }
            } else {
                st.push(cur);
                cur = cur->left;
            }
        }
        for (TreeNode* a : ans) {
            answ.push_back(a->val);
        }
        return answ;
    }
};
// [1, 2, 4, ]