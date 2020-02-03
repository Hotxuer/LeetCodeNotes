//
// Created by mac on 2020/2/3.
//

#include "problem.h"

// 暴力解法
 class Solution1 {
 public:
     string longestPalindrome(string s) {
         int maxLength = 0;
         int startIndex = 0;
         for (int i=0; i<s.size(); i++) {
             for (int j=i; j<s.size(); j++) {
                 if (j-i+1 <= maxLength) continue; // 如果这个子串长度小于当前已知最大的长度直接跳过
                 if (isPalindrome(s.substr(i, j-i+1))) {
                     maxLength = j-i+1;
                     startIndex = i;
                 }
             }
         }
         return s.substr(startIndex, maxLength);
     }
 private:
     bool isPalindrome(string s) {
         int size = s.size();
         for (int i=0; i<size/2; i++) {
             if (s[i] != s[size-1-i])
                 return false;
         }
         return true;
     }
 };

 // 字符串倒置动态规划找最大公共子串（考虑本身带非回文串的倒排串情况的剔除、空间的节省（用同一个一维数组不断覆盖））
 class Solution2 {
 public:
     string longestPalindrome(string s) {
         if (!s.size()) return "";
         // string reversed(s);
         // reverse(reversed.begin(), reversed.end());
         int maxLength = 0;
         int endIndex = 0;
         int size = s.size();
         vector<int> mat(size);
         for (int i=0; i<size; i++) {
             for (int j=size-1; j>=0; j--) {
                 if (s[i] == s[size-j-1]) {
                     if (i && j)
                         mat[j] = mat[j-1] + 1;
                     else
                         mat[j] = 1;
                     // 检测是否是本身带非回文串的倒排串的情况
                     if (i+j+2-mat[j]-size == 0 && mat[j] > maxLength) {
                         maxLength = mat[j];
                         endIndex = i;
                     }
                 } else {
                     mat[j] = 0; // 之前用二维数组的时候不用， 因为每次用的都是不用行之间的
                 }
             }
         }
         return s.substr(endIndex-maxLength+1, maxLength);
     }
 };

// 扩展中心的方法(中心有可能是两个也可能是一个NDD)
class Solution3 {
public:
    string longestPalindrome(string s) {
        int maxLength=0, maxStart=0;
        for (int i=0; i<s.size(); i++) {
            int len1 = centerExpand(s, i, i);
            int len2 = centerExpand(s, i, i+1);
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                maxStart = i-(maxLength-1)/2;
            }
        }
        return s.substr(maxStart, maxLength);
    }

private:
    int centerExpand(string s, int leftCenter, int rightCenter) {
        while (leftCenter>=0 && rightCenter<s.size() && s[leftCenter]==s[rightCenter]) {
            leftCenter--;
            rightCenter++;
        }
        return rightCenter-leftCenter-1;
    }
};