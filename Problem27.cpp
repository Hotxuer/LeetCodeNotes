//
// Created by mac on 2020/3/11.
//
#include "problem.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int length=0;
        int j=0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
};
