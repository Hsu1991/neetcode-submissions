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
    ListNode *result = nullptr, *result_curr = nullptr;
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // result, result_curr
        while(list1 != nullptr || list2 != nullptr)
        {
            if(list1 == nullptr){
                // put list2's nodes to result
                putNodeInResult(list2);
                break;
            } else if(list2 == nullptr) {
                // put list1's nodes to result
                putNodeInResult(list1);
                break;
            } else {
                // both list have nodes
                if(list1->val < list2->val) {
                    // put l1's node to result
                    putNodeInResult(list1);
                    list1 = list1->next;
                } else {
                    // put l2's node to result
                    putNodeInResult(list2);
                    list2 = list2->next;
                }
            }
        }
        return result;
    }
    void putNodeInResult(ListNode* node)
    {
        if(result == nullptr) {
            result = node;
        } else {
            result_curr->next = node;
        }
        result_curr = node;
    }

};
