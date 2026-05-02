/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
       // mistake 1: syntax error: prev = nullptr
        ListNode *curr = head, *prev = nullptr, *next = nullptr;
        while (curr != nullptr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
       // mistake 2: return curr instead of curr
        return prev;
    }
};
