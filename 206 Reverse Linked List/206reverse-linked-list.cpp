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
    ListNode* reverseList(ListNode* head) {
        auto temp = head;
        auto prev = head;
        int i {};
        while (temp != NULL) {
            if (i == 0) {
                auto t2 = temp->next;
                temp->next = NULL;
                temp = t2;
            }
            else {
                auto t2 = temp->next;
                temp->next = prev;
                prev = temp;
                temp = t2;
            }
            i++;
        }
        // while (prev != NULL) {
        //     std::cout << prev->val;
        //     prev = prev->next;
        // }
        return prev;
    }
};