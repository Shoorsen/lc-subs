/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;https://leetcode.com/problems/add-two-numbers/$0
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* cur_one = l1;
        ListNode* cur_two = l2;
        ListNode* answer = new ListNode{};
        ListNode* head = answer;
        int carry = 0;
        while(cur_one != nullptr && cur_two != nullptr) {
            int sum = cur_one->val + cur_two->val;
            cout << sum << endl;
            answer->val = (carry + sum) % 10;
            if (cur_one->next != nullptr && cur_two->next != nullptr) {
                answer->next = new ListNode{};
                answer = answer->next;
            }
            // answer = answer->next;
            if (sum + carry >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            cur_one = cur_one->next;
            cur_two = cur_two->next;
        }
        // return head;
        // cout << answer->val;
        while (cur_one != nullptr) {
            answer->next = new ListNode{};
            int sum = cur_one->val + carry;
            answer->next->val = (sum) % 10;
            answer = answer->next;
            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            cur_one=cur_one->next;
        }
        while (cur_two != nullptr) {
            answer->next = new ListNode{};
            int sum = cur_two->val + carry;
            answer->next->val = (sum) % 10;
            answer = answer->next;
            if (sum >= 10) {
                carry = 1;
            } else {
                carry = 0;
            }
            cur_two=cur_two->next;
        }
        if (carry == 1) {
            answer->next = new ListNode{1};
        }

        return head;
    }
};