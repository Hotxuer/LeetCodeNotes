//
// Created by mac on 2020/3/9.
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

// 纯交换(迭代)
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         if (!(head && head->next)) return head;
//         ListNode* temp1 = head;
//         ListNode* temp2 = temp1->next;
//         ListNode* temp3 = temp2->next;
//         ListNode* pre = NULL;
//         head = temp2;
//         while (temp2 != NULL) {
//             cout<< "haha";
//             if (pre) pre->next = temp2;
//             temp2->next = temp1;
//             temp1->next = temp3;
//             // 更新temp位置
//             pre = temp1;
//             temp1 = temp3;
//             temp2 = temp1 ? temp1->next : NULL;
//             temp3 = temp2 ? temp2->next : NULL;
//         }
//         return head;
//     }
// };

// 迭代重写
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* second;
        while (head && head->next) {
            second = head->next;
            pre->next = second;
            head->next = second->next;
            second->next = head;

            pre = head;
            head = pre->next;
        }
        return dummy->next;
    }
};

// 递归
 class Solution2 {
 public:
     ListNode* swapPairs(ListNode* head) {
         if (!(head && head->next)) return head;
         ListNode* second = head->next;
         head->next = swapPairs(second->next);
         second->next = head;
         return second;
     }
 };

