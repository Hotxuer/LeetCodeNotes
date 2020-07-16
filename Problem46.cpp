//
// Created by mac on 2020/7/16.
//

// dfs(回溯算法) 注意套路
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<bool> used(nums.size(), false);
        vector<int> track;
        dfs(result, track, nums, used);
        return result;
    }
private:
    void dfs(vector<vector<int>>& result, vector<int>& track, vector<int>& nums, vector<bool>& used) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (int i=0; i<nums.size(); i++) {
            if (used[i])
                continue;
            used[i] = true;
            track.push_back(nums[i]);
            dfs(result, track, nums, used);
            used[i] = false;
            track.pop_back();
        }
    }
};

