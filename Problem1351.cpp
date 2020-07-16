//
// Created by mac on 2020/2/17.
//

#include "problem.h"

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (int i=0; i<grid.size(); i++) {
            for (int j=0; j<grid[i].size(); j++) {
                if (grid[i][j]<0) result++;
            }
        }
        return result;
    }
};