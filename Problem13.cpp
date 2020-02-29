//
// Created by mac on 2020/2/28.
//

#include "problem.h"

class Solution {
public:
    int romanToInt(string s) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs [] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int result = 0;
        int pos = 0;
        for (int i=0; i<13; i++) {
            while (pos < s.size()) {
                if (strs[i] == s.substr(pos, strs[i].size())) {
                    result += values[i];
                    pos += strs[i].size();
                } else {
                    break;
                }
            }
        }
        return result;
    }
};