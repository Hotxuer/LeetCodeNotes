//
// Created by mac on 2020/7/7.
//

// 贪心算法（DP动态规划）
class Solution1 {
public:
    int lengthOfLIS(vector<int>& nums) {
        if (nums.size()<2)
            return nums.size();
        vector<int> tail;
        tail.push_back(nums[0]);
        for (int i=1; i<nums.size(); i++) {
            int temp = nums[i];
            if (temp>*(tail.end()-1)) {
                tail.push_back(temp);
            }
            else {
                for (int j=0; j<tail.size(); j++) {
                    if (tail[j]>=temp) {
                        tail[j] = temp;
                        break;
                    }
                }
            }
        }
        return tail.size();
    }
};

// 上述思路加二分查找，优化时间复杂度到O(nlogn)
class Solution2 {
public:
    int lengthOfLIS(vector<int> &nums) {
        int len = nums.size();
        if (len < 2) {
            return len;
        }

        vector<int> tail;
        tail.push_back(nums[0]);
        // tail 结尾的那个索引
        int end = 0;

        for (int i = 1; i < len; ++i) {
            if (nums[i] > tail[end]) {
                tail.push_back(nums[i]);
                end++;
            } else {
                int left = 0;
                int right = end;
                while (left < right) {
                    int mid = (left + right) >> 1;
                    if (tail[mid] < nums[i]) {
                        left = mid + 1;
                    } else {
                        right = mid;
                    }
                }
                tail[left] = nums[i];
            }
        }
        return end + 1;
    }