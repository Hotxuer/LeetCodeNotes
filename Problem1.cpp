//
// Created by mac on 2020/2/1.
//

#include "problem.h"

// 暴力法
class Solution1 {
public:
 vector<int> twoSum(vector<int>& nums, int target) {
     int size = nums.size();
     for (int i=0; i<size; i++) {
         for (int j=i+1; j<size; j++) {
             if (nums[i]+nums[j] == target) {
                 vector<int> results;
                 results.push_back(i);
                 results.push_back(j);
                 return results;
             }
         }
     }
     return vector<int>(2, -1);
 }
};

// 哈希映射
class Solution2 {
public:
vector<int> twoSum(vector<int>& nums, int target) {
    map<int, int> numMap;
    for (int i=0; i<nums.size(); i++) {
        if (numMap.count(target - nums[i])) {
            return {numMap[target - nums[i]], i};
        }
        numMap[nums[i]] = i;
    }
    return {-1, -1};
}
};
