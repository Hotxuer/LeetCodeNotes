//
// Created by mac on 2020/2/10.
//

#include "problem.h"

// 用到之前的反转整数，注意检测溢出（反转过程会溢出的整数一定不是回文数）
class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        int result = 0;
        int prev = x;
        int temp = 0;
        while (x != 0) {
            temp = x%10;
            if (result>INT_MAX/10 || (result==INT_MAX/10 && temp>7)) return false;
            result = result*10 + temp;
            x = x/10;
        }
        return prev == result;
    }
};