//
// Created by mac on 2020/7/16.
//

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // sort(nums.begin(), nums.end());
        fastSort(nums, 0, nums.size()-1);

        return nums[nums.size()-k];
    }
private:
    void fastSort(vector<int>& nums, int left, int right) {
        if (left<right) {
            int mid = partition(nums, left, right);
            fastSort(nums, left, mid);
            fastSort(nums, mid+1, right);
        }
    }

    int partition(vector<int>& nums, int left, int right) {
        int temp = nums[left];
        int t;
        while (left<right) {
            while (nums[right]>=temp && left<right)
                right--;
            t = nums[right];
            nums[right] = nums[left];
            nums[left] = t;
            while (nums[left]<=temp && left<right)
                left++;
            t = nums[right];
            nums[right] = nums[left];
            nums[left] = t;
        }
        nums[left] = temp;
        return left;
    }
};
