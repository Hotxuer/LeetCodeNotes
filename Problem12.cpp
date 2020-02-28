//
// Created by mac on 2020/2/28.
//

#include "problem.h"

// // 弱智解法
// class Solution {
// public:
//     string intToRoman(int num) {
//         string result("");
//         int thousands = num/1000;
//         num = num%1000;
//         result.append(thousands, 'M');
//         if (num >= 900) {
//             result.append("CM");
//             num -= 900;
//         }
//         if (num >= 500) {
//             result.append("D");
//             num -= 500;
//         }
//         if (num >= 400) {
//             result.append("CD");
//             num -= 400;
//         }
//         int hundred = num/100;
//         num = num%100;
//         result.append(hundred, 'C');
//         if (num >= 90) {
//             result.append("XC");
//             num -= 90;
//         }
//         if (num >= 50) {
//             result.append("L");
//             num -= 50;
//         }
//         if (num >= 40) {
//             result.append("XL");
//             num -= 40;
//         }
//         int ten = num/10;
//         num = num%10;
//         result.append(ten, 'X');
//         if (num >= 9) {
//             result.append("IX");
//             num -= 9;
//         }
//         if (num >= 5) {
//             result.append("V");
//             num -= 5;
//         }
//         if (num >= 4) {
//             result.append("IV");
//             num -= 4;
//         }
//         result.append(num, 'I');

//         return result;
//     }
// };

// 简洁写法
class Solution {
public:
    string intToRoman(int num) {
        int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string strs [] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};

        string result;
        for (int i=0; i<13; i++) {
            while (num >= values[i]) {
                result += strs[i];
                num -= values[i];
            }
        }
        return result;
    }
};

