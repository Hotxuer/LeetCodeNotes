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

// 两两merge(但时间超时)
// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         if (!lists.size()) return NULL;
//         ListNode* result = lists[0];
//         for (int i=1; i<lists.size(); i++) {
//             result = mergeTwoLists(result, lists[i]);
//         }
//         return result;
//     }

// private:
//     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
//         ListNode* result = new ListNode(0);
//         ListNode* temp = result;
//         while (l1 != NULL && l2 != NULL) {
//             if (l1->val > l2->val) {
//                 temp->next = new ListNode(l2->val);
//                 l2 = l2->next;
//             } else {
//                 temp->next = new ListNode(l1->val);
//                 l1 = l1->next;
//             }
//             temp = temp->next;
//         }
//         temp->next = l1 ? l1 : l2;
//         return result->next;
//     }
// };

// 自己又写了一个朴素算法，没精简，时间不超时
class Solution2 {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size()==0) return NULL;
        bool flag = true;
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        vector<int> nodeNumbers;
        for (ListNode* node:lists) {
            if (node!=NULL) {
                nodeNumbers.push_back(node->val);
            } else {
                nodeNumbers.push_back(INT_MAX);
            }
        }
        while (1) {
            int minNumber = nodeNumbers[0];
            int minIndex = 0;
            for (int i=0; i<nodeNumbers.size(); i++) {
                if (nodeNumbers[i] < minNumber) {
                    minNumber = nodeNumbers[i];
                    minIndex = i;
                }
            }
            if (minNumber != INT_MAX) {
                temp->next = new ListNode(minNumber);
                temp = temp->next;
                if (lists[minIndex]->next!=NULL) {
                    nodeNumbers[minIndex] = lists[minIndex]->next->val;
                    lists[minIndex] = lists[minIndex]->next;
                } else {
                    nodeNumbers[minIndex] = INT_MAX;
                }
            } else {
                break;
            }
        }
        return result->next;

    }
};

// 分治法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*> &lists) {
        int length = lists.size();
        if (length == 0) return NULL;
        if (length == 1) return lists[0];
        if (length == 2) return mergeTwoLists(lists[0], lists[1]);
        int mid = length/2;
        vector<ListNode*> left(lists.begin(), lists.begin()+mid);
        vector<ListNode*> right(lists.begin()+mid, lists.end());
        return mergeTwoLists(mergeKLists(left), mergeKLists(right));
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* temp = result;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val > l2->val) {
                temp->next = new ListNode(l2->val);
                l2 = l2->next;
            } else {
                temp->next = new ListNode(l1->val);
                l1 = l1->next;
            }
            temp = temp->next;
        }
        temp->next = l1 ? l1 : l2;
        return result->next;
    }
};

