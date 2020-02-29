//
// Created by mac on 2020/2/29.
//

#include "problem.h"

 class Solution {
 public:
     vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
         if (nums.size() < 3) return result;
         sort(nums.begin(), nums.end());
         if (nums[0] > 0) return result;
         int m = 0, n = 0;
         for (int i=0; i<nums.size(); i++) {
             if (i!=0 && nums[i]==nums[i-1]) continue;
             if (nums[i] > 0) break;
             m = i+1;
             n = nums.size() - 1;
             while (m < n) {
                 int temp = nums[i]+nums[m]+nums[n];
                 if (temp == 0) {
                     if (m!=i+1 && nums[m]==nums[m-1]) {
                         m++;
                         continue;
                     }
                     if (n!=nums.size()-1 && nums[n]==nums[n+1]) {
                         n--;
                         continue;
                     }
                     vector<int> vec({nums[i], nums[m], nums[n]});
                     result.push_back(vec);
                     m++;
                     n--;
                 } else {
                     if (temp > 0)
                         n--;
                     else
                         m++;
                 }
             }
         }
         return result;
     }
 };

// 在每次发现一个解后直接用while移到不重复的地方，而不是在每次找到新的解才验证，更加节省时间
// 此外转换为long long避免溢出
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        if(nums.size()<3) return ans;
        sort(nums.begin(), nums.end());
        if(nums[0]>0) return ans;
        int i = 0;
        while(i<nums.size()){
            int left = i+1, right = nums.size()-1;
            while(left< right){
                if(nums[i]>0) break;
                // 转换为long long避免加法过程中溢出
                long long y = static_cast<long long>(nums[i]);
                long long x = static_cast<long long>(nums[left]);
                long long z = static_cast<long long>(nums[right]);
                if(x + y >0-z)
                    right--;
                else if(x + y <0-z)
                    left++;
                else{
                    ans.push_back({nums[i], nums[left], nums[right]});
                    // 相同的left和right不应该再次出现，因此跳过
                    while(left<right&&nums[left]==nums[left+1])
                        left++;
                    while(left<right&&nums[right] == nums[right-1])
                        right--;
                    left++;
                    right--;
                }
            }
            // 避免nums[i]作为第一个数重复出现
            while(i+1<nums.size()&&nums[i] == nums[i+1])
                i++;
            i++;
        }
        return ans;
    }
};

