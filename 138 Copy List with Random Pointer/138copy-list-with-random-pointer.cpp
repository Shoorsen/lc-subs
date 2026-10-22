/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

void debug(Node* head) {
    auto temp = head;
    while (temp != nullptr) {
        auto t =temp->random ? temp->random->val : 0;
        cout << "val: " << temp->val << " random: " << t << endl;
        temp = temp->next;
    }
    cout << endl;
}

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) {
            return nullptr;
        }

        auto orig = head;
        Node* newHead = nullptr;
        while (orig != nullptr) {
            newHead = new Node{orig->val};
            newHead->next = orig->next;
            orig->next = newHead;
            orig = orig->next->next;
        }

        orig = head;
        newHead = head->next;
        // cout << orig->next->next->val << endl;
        // debug(newHead);
        while(orig != nullptr) {
            // cout << orig->val << endl;
            if (orig->random == nullptr) {
                newHead->random = nullptr;
            } else {
                newHead->random = orig->random->next;
            }

            // newRandom = orig->random->next;
            orig = newHead->next;
            if (newHead->next == nullptr) {
                newHead = nullptr;
            } else {
                newHead = newHead->next->next;
            }
        }

        // debug(head);

        orig = head;
        newHead = head->next;
        auto headbug = newHead;
        while (orig != nullptr) {
            // if (newHead) {
            orig->next = newHead->next;
            if (newHead->next) newHead->next = newHead->next->next;
            // } else {
            //     cout << orig->val;
            // }
            orig = orig->next;
            newHead=newHead->next;
        }
        // debug(head);
        // debug(headbug);

        return headbug;
    }
};