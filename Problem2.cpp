//
// Created by mac on 2020/2/1.
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

 // 第一版
 class Solution1 {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* result = new ListNode((l1->val+l2->val)%10);
         ListNode* current = result;
         int carry = (l1->val+l2->val)/10;
         while (l1->next != NULL && l2->next != NULL) {
             l1 = l1->next;
             l2 = l2->next;
             current->next = new ListNode((l1->val+l2->val+carry)%10);
             carry = (l1->val+l2->val+carry)/10;
             current = current->next;
         }
         ListNode* rest = l1->next == NULL ? l2->next : l1->next;
         while (rest != NULL) {
             current->next = new ListNode((rest->val+carry)%10);
             carry = (rest->val+carry)/10;
             rest = rest->next;
             current = current->next;
         }
         if (carry > 0) {
             current->next = new ListNode(1);
         }

         return result;
     }
 };

 // 第二版（简练版）
 class Solution2 {
 public:
     ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         ListNode* resultHead = new ListNode(-1);
         ListNode* currentNode = resultHead;
         int carry = 0;
         int a, b;
         while (l1 != NULL || l2 != NULL) {
             if (l1 == NULL) {
                 a = 0;
             } else {
                 a = l1->val;
                 l1 = l1->next;
             }
             if (l2 == NULL) {
                 b = 0;
             } else {
                 b = l2->val;
                 l2 = l2->next;
             }
             currentNode->next = new ListNode((a+b+carry)%10);
             currentNode = currentNode->next;
             carry = (a+b+carry)/10;
         }
         if (carry != 0) {
             currentNode->next = new ListNode(carry);
         }

         return resultHead->next;
     }
 };

// 第三版（直接用l1存放结果）
class Solution3 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* res = l1;
        char tem_r = 0;

        while (1) {
            tem_r = l1->val + l2->val + tem_r;
            l1->val = tem_r%10;
            tem_r /= 10;

            if(l1->next && l2->next)
            {
                l1 = l1->next;
                l2 = l2->next;
            }
            else
            {
                if(l2->next)//此时l1->next必然为NULL
                    l1->next = l2->next;
                while(l1->next)
                {
                    l1 = l1->next;
                    tem_r = l1->val + tem_r;
                    l1->val = tem_r%10;
                    tem_r /= 10;
                    if(tem_r == 0)
                    {
                        //不会再进位了,则后面的计算都是浪费，提前终止
                        break;
                    }
                }
                if(tem_r)
                    l1->next = new ListNode(tem_r);
                break;
            }
        }

        return res;
    }
};