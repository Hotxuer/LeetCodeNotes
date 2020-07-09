//
// Created by mac on 2020/7/9.
//

// 同上一题的思路，O(n^2)的复杂度
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int result = nums[0]+nums[1]+nums[2];
        int m, n;
        for (int i=0; i<nums.size()-2; i++) {
            m = i+1;
            n = nums.size()-1;
            while (m<n) {
                int temp = nums[i]+nums[m]+nums[n];
                if (temp==target) return target;
                if (abs(temp-target)<abs(result-target)) {
                    result = temp;
                }
                if (temp < target) {
                    m++;
                } else {
                    n--;
                }
            }
        }
        return result;
    }
};