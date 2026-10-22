/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void debug(ListNode* debug) {
        while (debug != nullptr) {
            cout << debug->val << endl;
            debug=debug->next;
        }
    }
    void reorderList(ListNode* head) {
        if (head->next == nullptr) {
            return;
        }
        auto tail = head;
        int n = 0;
        while (tail->next != nullptr) {
            tail = tail->next;
            n++;
        }
        auto cur = head;
        ListNode* prev = cur;
        for(int i = 0; i < n/2; i++) {
            cur=cur->next;
        }

        prev = cur;
        cur = cur->next;
        prev->next = nullptr;

        // cout << cur->val << " " << prev->val << endl;
        
        ListNode* rev = nullptr;
        ListNode* rhs = nullptr;
        while (cur != nullptr) {
            // bug = cur;
            rhs = cur;
            auto next = cur->next;
            cur->next = rev;
            rev = cur;
            cur = next;
        }

        ListNode* res = head;
        ListNode* lhs = head;
        // debug(lhs);
        // cout << "BREAK" << endl;
        // debug(rhs);
        for (int i = 0; i <= n; i++) {
            if (i == 0) {
                res = lhs;
                lhs=lhs->next;
                res->next = nullptr;
                continue;
            }
            if (i%2 == 0) {
                res->next = lhs;
                lhs=lhs->next;
                res = res->next;
                res->next = nullptr;
                if (lhs != nullptr) cout << lhs->val << " " << res->val << endl;

            } else {
                res->next = rhs;
                // debug(head);
                if (rhs != nullptr) rhs = rhs->next;
                res = res->next;
                if (res != nullptr) res->next = nullptr;
            }
        }
    }
};