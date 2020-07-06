//
// Created by mac on 2020/3/11.
//
#include "problem.h"

// 用vector的erase函数，但效率会比较低
// class Solution {
// public:
//     int removeDuplicates(vector<int>& nums) {
//         if (nums.size() == 0) return 0;
//         int length = 1;
//         for (int i=1; i<nums.size(); i++) {
//             if (nums[i] == nums[i-1]) {
//                 nums.erase(nums.begin()+i);
//                 i--;
//             } else {
//                 length++;
//             }
//         }
//         return length;
//     }
// };

// 双指针，不需要删除，直接改变数组即可（因为最后的结果是取前N的，N是返回的int）
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int j = 0;
        for (int i = 1; i < nums.size(); i++)
            if (nums[j] != nums[i]) nums[++j] = nums[i];
        return ++j;
    }
};

