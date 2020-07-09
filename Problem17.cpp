//
// Created by mac on 2020/3/2.
//

#include "problem.h"

// 使用递归
// class Solution {
// public:
//     vector<string> letterCombinations(string digits) {
//         vector<string> newRes;
//         if (!digits.size()) return newRes;

//         char curChar = digits[0];
//         string strs = stringMap[curChar];
//         for (char c: strs) {
//             newRes.push_back(string(1, c));
//         }
//         return twoCombinations(newRes, digits);
//     }
// private:
//     map<char, string> stringMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
//         {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

//     vector<string> twoCombinations(vector<string>& oldRes, string digits) {
//         if (digits.size()==1) // 这是最后一个字母了
//             return oldRes;

//         char curChar = digits[1];
//         string strs = stringMap[curChar];
//         vector<string> newRes;
//         for (string tem: oldRes) {
//             for (int i=0; i<strs.size(); i++) {
//                 newRes.push_back(tem+strs[i]);
//             }
//         }
//         return twoCombinations(newRes, digits.substr(1, digits.size()-1));
//     }
// };

// 代码简洁规范化
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (!digits.size()) return result;
        return twoCombinations(result, digits, 0);
    }
private:
    map<char, string> stringMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    vector<string> twoCombinations(vector<string>& result, string digits, int index) {
        char curChar = digits[index];
        string strs = stringMap[curChar];
        if (index) {
            if (index == digits.size()) return result;
            int resLength = result.size();
            for (int i=0; i<resLength; i++) {
                for (char c: strs) {
                    result.push_back(result[i]+c);
                }
            }
            //  删除之前的那些
            result.erase(result.begin(), result.begin()+resLength);
        } else {
            for (char c: strs) {
                result.push_back(string(1, c));
            }
        }
        return twoCombinations(result, digits, index+1);
    }
};

// 最简版本，不用重复调用函数
class Solution3 {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        map<char, string> stringMap{{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
                                    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        for (char d:digits) {
            if (!result.size()) { // 第一个字母时
                for (char newChar:stringMap[d]) {
                    result.push_back(string(1, newChar));
                }
            } else { // 已经有字母
                int size = result.size();
                for (int i=0; i<size; i++) {
                    for (char newChar:stringMap[d]) {
                        result.push_back(result[i]+newChar);
                    }
                }
                result.erase(result.begin(), result.begin()+size);
            }
        }
        return result;
    }
};

