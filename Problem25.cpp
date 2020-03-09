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
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int kNum = k;
        ListNode* cur = head;
        while (cur->next && --kNum) cur = cur->next;
        if (cur->next)
            cur->next = reverseKGroup(cur->next, k);
        return reverseK(head, k);
    }

private:
    // 翻转前k个节点
    ListNode* reverseK(ListNode* head, int k) {
        if (!k) return head;
        // 如果k大于总长，那就不能变
        ListNode* cur = head;
        int kNum = k;
        while (cur && kNum--) cur = cur->next;
        if (kNum > 0) return head;
        // 总长足够，开始翻转
        ListNode* firstNode = head;
        ListNode* secondNode = head->next;
        ListNode* thirdNode = NULL;
        head->next = NULL;
        while (secondNode && --k) {
            thirdNode = secondNode->next;
            secondNode->next = firstNode;
            // 向后更新
            firstNode = secondNode;
            secondNode = thirdNode;
        }
        if (secondNode) head->next = secondNode; // 如果k小于总长还要把后面没颠倒的接上
        return firstNode;
    }
};

// 思路有一点麻烦，也可以不用递归，从开头开始，每k个为一组，数目足够就断开，进入无脑反转函数，然后再连起来，继续向前进行

