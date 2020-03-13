//
// Created by mac on 2020/3/13.
//
#include "problem.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.size()) return 0;
        if (needle.size() > haystack.size()) return -1;
        for (int i=0; i<haystack.size(); i++) {
            int m=i, n=0;
            while (m<haystack.size() && n<needle.size() && haystack[m]==needle[n]) {
                m++;
                n++;
            }
            if (n==needle.size()) return i;
        }
        return -1;
    }
};