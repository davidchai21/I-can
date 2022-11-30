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
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* cur = dummy, *tail = head;
        while (head) {
            head = head->next;
            if (n) {
                --n;
            } else {
                cur = cur->next;
            }
        }
        tail = cur->next;
        cur->next = tail->next;
        tail->next = nullptr;
        delete(tail);
        head = dummy->next;
        dummy->next = nullptr;
        delete(dummy);
        return head;
    }
};