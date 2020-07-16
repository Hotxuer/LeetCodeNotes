//
// Created by mac on 2020/7/16.
//

// 贪心算法，看当前最远能跳到几，maxright之前的都可以到达NDD
class Solution {
public:
    bool canJump(vector<int>& nums) {
        if (nums.size() < 2) return true;
        int maxRight = 0;
        for (int i=0; i<nums.size()-1 && i<=maxRight; i++) {
            maxRight = max(maxRight, nums[i]+i);
            if (maxRight>=nums.size()-1)
                return true;
        }
        return false;
    }
};

