//
// Created by mac on 2020/2/9.
//

#include "problem.h"

class Solution {
public:
    int myAtoi(string str) {
        int result = 0;
        bool positive = 1;
        int temp = 0;
        int i = 0;
        // int prev = 0;
        // 排除空格
        while (str[i] == ' ') i++;
        // 正负号
        if (str[i] == '-') positive = 0;
        if (str[i] == '+' || str[i] == '-') i++;
        // 开始计算
        while (i<str.size() && str[i] >= '0' && str[i] <= '9') {
            temp = int(str[i] - '0');
            // 检查溢出1 (累加之间检查加之后是否会溢出)
            if (result>INT_MAX/10 || (result==INT_MAX/10 && temp>7))
                return positive>0 ? INT_MAX : INT_MIN;
            result = result*10 + temp;
            i++;
            // 检查溢出2（看累加之后的结果逆累加之后是否和原结果一样）这种方法C++不可用，因为C++溢出编译器会直接报错。
            // 但JAVA可用，因为JAVA溢出不会报错，会重新解释，所以逆运算得不到原来的结果。
            // if ((result-temp)/10 != prev)
            //     return positive>0 ? INT_MAX : INT_MIN;
            // prev = result;
        }
        return positive ? result : -result;
    }
};

