//
// Created by mac on 2020/3/4.
//
#include "problem.h"

// class Solution {
// public:
//     bool isValid(string s) {
//         stack<int> stack;
//         for (char c: s) {
//             switch (c) {
//                 case '(':
//                     stack.push_back(1);
//                     break;
//                 case ')':
//                     if (!stack.size() || stack.back() != 1)
//                         return false;
//                     stack.pop_back();
//                     break;
//                 case '{':
//                     stack.push_back(2);
//                     break;
//                 case '}':
//                     if (!stack.size() || stack.back() != 2)
//                         return false;
//                     stack.pop_back();
//                     break;
//                 case '[':
//                     stack.push_back(3);
//                     break;
//                 case ']':
//                     if (!stack.size() || stack.back() != 3)
//                         return false;
//                     stack.pop_back();
//                     break;
//             }
//         }
//         if (stack.size())
//             return false;
//         else
//             return true;
//     }
// };

// 思路一致但是写法简洁版
class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (char c: s) {
            if (charStack.empty()) {
                charStack.push(c);
                continue;
            } else if (isSame(charStack.top(), c)) {
                charStack.pop();
            } else {
                charStack.push(c);
            }
        }
        return charStack.empty();
    }
private:
    bool isSame(char left, char right) {
        return (left=='('&&right==')' || left=='['&&right==']' || left=='{'&&right=='}');
    }
};

