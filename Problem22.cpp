//
// Created by mac on 2020/3/6.
//

#include "problem.h"

// 递归加DFS
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<string> result;
//         generate(result, "", 0, 0, n);
//         return result;
//     }
// private:
//     void generate(vector<string>& result, string str, int leftNum, int rightNum, int n) {
//         if (rightNum==n && leftNum==n) {
//             result.push_back(str);
//             return;
//         }
//         if (leftNum>n || rightNum>n || rightNum>leftNum) return;
//         generate(result, str+'(', leftNum+1, rightNum, n);
//         generate(result, str+')', leftNum, rightNum+1, n);
//         return;
//     }
// };

// 递归加DFS好懂版本
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        dfs(n, n, "");
        return result;
    }
private:
    vector<string> result;
    void dfs(int left, int right, string str) {
        if (left==0 && right==0){
            result.push_back(str);
        } else {
            if (left>0) {
                dfs(left-1, right, str+'(');
            }
            if (right>left) {
                dfs(left, right-1, str+')');
            }
        }
    }
};

// 动态规划
// 如果知道了n=k-1全部的组合，求n=k的组合。
// 那么假设n=k时左括号在最左边的那组括号是新加入的一组括号，那么剩下的k-1组括号要么在这组括号的里面，要么在这组括号的右边NDD
// class Solution {
// public:
//     vector<string> generateParenthesis(int n) {
//         vector<vector<string>> result; // 存放从0到n的括号组合情况
//         result.push_back(vector<string>({""})); // n=0的时候是空数组
//         result.push_back(vector<string>({"()"})); // n=1
//         for (int i=2; i<n+1; i++) {
//             vector<string> current;
//             for (int j=0; j<i; j++) {
//                 int h = i-j-1; // 分j和h两半NDD
//                 for (string l:result[j])
//                     for (string r:result[h])
//                         current.push_back('('+l+')'+r);
//             }
//             result.push_back(current);
//         }
//         return result[n];
//     }
// };

// 动态规划简洁版本（不存储之前的结果)
class Solution2 {
public:
    vector<string> generateParenthesis(int n) {
        if (n==0) return {""};
        if (n==1) return {"()"};
        if (n==2) return {"()()", "(())"};
        vector<string> result;
        for (int i=0; i<n; i++) {
            int j = n-i-1;
            vector<string> left = generateParenthesis(i);
            vector<string> right = generateParenthesis(j);
            for (string l:left)
                for (string r:right)
                    result.push_back('('+l+')'+r);
        }
        return result;
    }
};

