//
// Created by mac on 2020/3/4.
//

#include "problem.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while (l1 && l2) {
            if (l1->val > l2->val) {
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            temp = temp->next;
        }
        temp -> next = l1 ? l1 : l2;
        return result->next;
    }
};

