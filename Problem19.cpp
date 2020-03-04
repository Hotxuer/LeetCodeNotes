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
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//         ListNode* target = head;
//         ListNode* temp = head;
//         int num = 0;
//         while (temp->next != NULL) {
//             temp = temp->next;
//             if (num < n) {
//                 num++;
//             } else {
//                 target = target->next;
//             }
//         }
//         if (num == n) {
//             target->next = target->next->next;
//         } else {
//             return head->next;
//         }

//         return head;
//     }
// };

// 快指针直接啥都不管先走n步，慢指针再一起走，如果快指针已经直接走到NULL了，则说明删除第一个元素，直接返回head->next
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head | !head -> next) return NULL;
        ListNode * fast = head, *slow = head;
        for(int i = 0; i < n; i++){
            fast = fast -> next;
        }
        if(!fast){
            return head -> next;
        }

        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        slow -> next = slow -> next -> next;
        return head;
    }
};

