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
    ListNode* removeNthFromEnd(ListNode* head, int n) {        
        if (head->next == nullptr) {
            head = nullptr;
            return head;
        }
        int sz = 0;
        auto counter = head;
        while (counter != nullptr) {
            counter = counter->next;
            sz++;
        }
        
        auto cur = head;
        if (n == sz) {
            head = head->next;
            return head;
        }
        for(int i = 0; i < sz-n-1; i++) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return head;
    }
};