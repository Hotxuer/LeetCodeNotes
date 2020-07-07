//
// Created by mac on 2020/7/7.
//

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        if (!size)return -1;
        int left = 0, right = size-1;
        while (left<=right) { // 注意可以是相等，举例三个的那种情况NDD
            int mid = (left+right)/2; // 注意mid是进来再设定
            if (target==nums[mid])
                return mid;
            if (nums[mid]<nums[right]) { // 右边是有序的
                // 判断在不在右边
                if (nums[mid]<target && target<=nums[right]) { // 在右边
                    left = mid+1;
                } else { // 在左边
                    right = mid-1;
                }
            } else { // 左边是有序的
                if (nums[mid]>target && nums[left]<=target) { // 在左边
                    right = mid-1;
                } else {
                    left = mid+1;
                }
            }
        }
        return -1;
    }
};
