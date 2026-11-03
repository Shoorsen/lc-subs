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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p==nullptr || q == nullptr) {
            return false;
        }
        if (p->val != q->val) {
            return false;
        }
        std::stack<TreeNode*> st1;
        std::stack<TreeNode*> st2;
        st1.push(p);
        st2.push(q);

        while (!st1.empty()) {
            if (st2.empty()) {
                return false;
            }
            auto t1 = st1.top();
            st1.pop();
            auto t2 = st2.top();
            st2.pop();
            if ((t1 == NULL && t2 != NULL) || (t2 == NULL && t1 != NULL)) {
                return false;
            }
            if (t1 == NULL && t2 == NULL) {
                continue;
            }
            if (t1->val != t2->val) {
                return false;
            }
            st1.push(t1->left);
            st1.push(t1->right);
            st2.push(t2->left);
            st2.push(t2->right);
        }
        return true;

    }
};