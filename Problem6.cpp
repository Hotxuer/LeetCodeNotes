//
// Created by mac on 2020/2/4.
//

#include "problem.h"

class Solution {
public:
    string convert(string s, int numRows) {
        // numRows是1直接返回原字符串
        if (numRows==1)
            return s;
        string result;
        int index = 0;
        int intervalSum = 0;
        int interval;
        // 按行读取
        for (int i=0; i<numRows; i++) {
            index = i;
            // 确定在当前行相邻字符在原字符串之间的间隔
            intervalSum = 2*(numRows-1);
            if (i==0 || i==numRows-1)
                interval = 2*numRows-2;
            else
                interval = intervalSum - 2*i;
            while (index < s.size()) {
                result.append(1, s[index]);
                index += interval;
                if (i!=0 && i!=numRows-1)
                    interval = intervalSum - interval;
            }
        }
        return result;
    }
};

// 另一种方法是找numRows的vector从左到右把s按行分类，较简单略去
