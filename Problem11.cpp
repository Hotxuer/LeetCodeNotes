//
// Created by mac on 2020/2/27.
//

#include "problem.h"

// 暴力法
// class Solution {
// public:
//     int maxArea(vector<int>& height) {
//         int max = 0;
//         int temp = 0;
//         for(int i=0; i<height.size(); i++) {
//             for (int j=i+1; j<height.size(); j++) {
//                 temp = min(height[i], height[j])*(j-i);
//                 // max = max(max, temp);
//                 if (temp>max) max = temp;
//             }
//         }
//         return max;
//     }
// };

// 动态规划（从两边向中间检索，检索方向向小的边界一侧移动)
class Solution {
public:
    int maxArea(vector<int>& height) {
        int result = 0, temp = 0;
        int i = 0, j = height.size()-1;
        while (j>i) {
            temp = min(height[i], height[j])*(j-i);
            result = max(result, temp);
            if (height[i]>height[j])
                j--;
            else
                i++;
        }
        return result;
    }
};