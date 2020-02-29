//
// Created by mac on 2020/2/28.
//

#include "problem.h"

class Solution1 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string result("");
        string first(strs[0]);
        for (int i=0; i<first.size(); i++) {
            char temp = first[i];
            int j=1;
            for (j=1; j<strs.size(); j++)
                if (strs[j][i] != temp) break;
            if (j != strs.size())
                break;
            else
                result += temp;
        }
        return result;
    }
};

// 小改进减小内存占用（但不知为什么时间增加了？）
class Solution2 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (!strs.size()) return "";
        string first(strs[0]);
        int i=0, j=1;
        for (int i=0; i<first.size(); i++) {
            char temp = first[i];
            for (j=1; j<strs.size(); j++)
                if (strs[j][i] != temp) break;
            if (j != strs.size())
                break;
        }
        return first.substr(0, i);
    }
};

