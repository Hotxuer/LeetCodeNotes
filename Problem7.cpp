//
// Created by mac on 2020/2/4.
//

#include "problem.h"

// 纯数学方法，不转字符串，但要防止溢出
class Solution {
public:
    int reverse(int x) {
        long result = 0;
        int max = 0x7fffffff;
        int min = 0x80000000;
        while (x != 0) {
            result = result*10 + x%10;
            x = x/10;
        }
        cout<<max<<" "<<min<<endl;
        return (result > max || result < min) ? 0 : result;
    }
};