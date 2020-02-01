//
// Created by mac on 2020/2/1.
//

#include "problem.h"

 class Solution1 {
 public:
     double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
         return findMedianRecurrence(nums1, nums2);
     }

 private:
     double findMedianRecurrence(vector<int>& num1, vector<int>& num2) {
         // 如果有一个是零
         if (!num2.size()) {
             return double(num1[(num1.size())/2]+num1[(num1.size()-1)/2])/2;
         }
         if (!num1.size()) {
             return double(num2[(num2.size())/2]+num2[(num2.size()-1)/2])/2;
         }
         // 两个都不是零，那么分为是两个都只有一个数和不是
         if (num1.size()==1 && num2.size()==1) {
             return double(num1[0]+num2[0])/2;
         } else {
             // 要警惕第一下把一个vector删到空的情况
             int start1 = num1[0], start2 = num2[0];
             int end1 = num1[num1.size()-1], end2 = num2[num2.size()-1];
             if (start1<start2) {
                 num1.erase(num1.begin());
             } else {
                 num2.erase(num2.begin());
             }
             if (end1>=end2) {
                 num1.pop_back();
             } else {
                 num2.pop_back();
             }
             return findMedianRecurrence(num1, num2);
         }
     }
 };

// 以上复杂度应该是O(m+n)，以下用递归、二分查找法实现
class Solution2 {
public:
    double findMedianSortedArrays(vector<int>& num1, vector<int>& num2) {
        int k1 = (num1.size()+num2.size()+1)/2;
        int k2 = (num1.size()+num2.size()+2)/2;
        return double(findKth(num1, 0, num2, 0, k1)+findKth(num1, 0, num2, 0, k2))/2;
    }

private:
    int findKth(vector<int>& num1, int beginner1, vector<int>& num2, int beginner2, int k) {
        // 如果有某个数组已经为空
        if (num1.size()<=beginner1)
            return num2[beginner2+k-1];
        if (num2.size()<=beginner2)
            return num1[beginner1+k-1];
        // 如果K是1，那么直接取两个数组开头较小的那一个即可
        if (k==1)
            return min(num1[beginner1], num2[beginner2]);
        // 使用二分法进行查找
        int midValue1 = (beginner1+k/2 <= num1.size()) ? num1[beginner1+k/2-1] : INT_MAX;
        int midValue2 = (beginner2+k/2 <= num2.size()) ? num2[beginner2+k/2-1] : INT_MAX;
        if (midValue1 > midValue2)
            return findKth(num1, beginner1, num2, beginner2+k/2, k-k/2);
        else
            return findKth(num1, beginner1+k/2, num2, beginner2, k-k/2);
    }
};
