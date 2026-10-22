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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        auto cur1 = list1;
        auto cur2 = list2;
        ListNode* cur;
        ListNode* head;
        if (cur1 == nullptr) {
            return cur2;
        }
        if (cur2 == nullptr) {
            return cur1;
        }

        if (cur1->val < cur2->val) {
            head = cur1;
            cur1=cur1->next;
        } else {
            head = cur2;
            cur2=cur2->next;
        }
        cur = head;
        while (cur1 != nullptr && cur2 != nullptr) {
            if (cur1->val < cur2->val) {
                cur->next = cur1;
                cur1 = cur1->next;
            } else {
                // std::cout << cur2->val << std::endl;

                cur->next = cur2;
                cur2 = cur2->next;
            }
            cur = cur->next;
            // cur->next = nullptr;
        }
        // std::cout << cur->val << std::endl;
        auto debug = head;
        // while (debug != nullptr) {
        //     std::cout << debug->val << std::endl;
        //     debug=debug->next;
        // }
        while (cur1!=nullptr) {
            auto debug = cur;
            while (debug != nullptr) {
                std::cout << debug->val << endl;
                debug = debug->next;
            }
            // std::cout << cur1->val << std::endl;
            cur->next = cur1;
            cur = cur->next;
            cur1=cur1->next;
        }
        while (cur2 != nullptr) {
            cur->next = cur2;
            cur = cur->next;
            cur2=cur2->next;
        }
    return head;
    }
};