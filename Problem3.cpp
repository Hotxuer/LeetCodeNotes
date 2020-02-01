//
// Created by mac on 2020/2/1.
//

#include "problem.h"

 // 第一版，新开空间用于记录，查询之前是否出现用的是遍历
 class Solution1 {
 public:
     int lengthOfLongestSubstring(string s) {
         vector<char> exists;
         int currentLength = 0, maxLength = 0;
         int index;
         for (int i=0; i<s.size(); i++) {
             // 查找当前队列是否有该元素
             for (index=0; index<exists.size(); index++) {
                 if (exists[index] == s[i])
                     break;
             }

             if (index != exists.size()) {
                 maxLength = max(maxLength, int(exists.size()));
                 exists.erase(exists.begin(), exists.begin()+index+1);
                 exists.push_back(s[i]);
             } else {
                 exists.push_back(s[i]);
             }
         }
         maxLength = max(maxLength, int(exists.size()));
         return maxLength;
     }
 };

// 第二版，滑动窗口，查询用的是哈希，哈希表记录对应的index，直接在原数组上面移动，空间更节省(但实际结果更差？)
class Solution2 {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> exists;
        int maxLength = 0;
        int i, j;
        for (i=0, j=0; j<s.size(); j++) {
            if (exists.count(s[j]) && exists[s[j]] >= i) {
                i = exists[s[j]]+1;
            } else {
                maxLength = max(maxLength, j-i+1);
            }
            exists[s[j]] = j;
        }
        return maxLength;
    }
};