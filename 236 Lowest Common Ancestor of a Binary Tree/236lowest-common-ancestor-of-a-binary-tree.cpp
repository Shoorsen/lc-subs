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
    std::unordered_map<TreeNode*, TreeNode*> preds;
    bool found = false;
    void dfs(TreeNode* root, TreeNode* n) {
        // cout << n->val << endl;
        if (root == nullptr) {
            return;
        }
        if (root == n) {
            found = true;
            return;
        }
        if (root->left != nullptr) {
            preds[root->left] = root;
            if (!found) dfs(root->left, n);
        }
        if (root->right != nullptr) {
            preds[root->right] = root;
            if (!found) dfs(root->right, n);
        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p);
        found = false;
        dfs(root, q);
        // for (const auto& pair : preds) {
        //     cout << "CHILD: " << pair.first->val << endl;
        //     cout << "PARENT: " << pair.second->val << endl;
        // }

        std::unordered_set<TreeNode*> parents;
        preds[root] = nullptr;
        TreeNode* pval = p;
        parents.insert(pval);

        while (preds[pval] != nullptr) {
            parents.insert(preds[pval]);
            pval = preds[pval];
        }
        TreeNode* qval = q;
        for (const auto& node : parents) {
            if (node != nullptr) cout << node->val << endl;
        }
        while (parents.find(qval) == parents.end()) {
            qval = preds[qval];
        }
        return qval;
        // std::stack<TreeNode*> st;
        // std::unordered_map<int, int> pred;
        // while (root != nullptr) {
        //     if (root->val==p->val) {
        //         break;
        //     }
        //     if (root->left != nullptr) {
        //         pred[root->left->val] = root->val;
        //         st.push(root->left);
        //     }
        //     if (root->right != nullptr) {
        //         pred[root->left->val] = root->val;
        //         st.push(root->right);
        //     }
        // }
    }
};