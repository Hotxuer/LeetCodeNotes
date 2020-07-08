//
// Created by mac on 2020/7/8.
//

// 动态规划，dp[i][j]代表s前i匹配p前j
class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> matchDp(s.size()+1, vector<bool>(p.size()+1, false));
        matchDp[0][0] = true;
        // matchDp[0][1] = false;
        // matchDp[1][0] = false;
        // ** 的情况应该是不考虑
        for (int i=1; i<p.size(); i++) {
            if (p[i]=='*' && matchDp[0][i-1]) {
                matchDp[0][i+1] = true;
            }
        }
        for (int i=0; i<s.size(); i++) {
            for (int j=0; j<p.size(); j++) {
                if (p[j]=='.' || s[i]==p[j]) {
                    matchDp[i+1][j+1] = matchDp[i][j];
                }
                if (p[j]=='*') {
                    if (p[j-1]!=s[i] && p[j-1]!='.') {
                        matchDp[i+1][j+1] = matchDp[i+1][j-1];
                    } else {
                        // match[i][j]不行吗？:不行, [i][j+1]匹配的是*代表多个的情况，用[i][j]前面可能还要用到*但没把最后的那个*包含进去，导致破坏了前面
                        matchDp[i+1][j+1] = (matchDp[i+1][j-1] || matchDp[i+1][j] || matchDp[i][j+1]);
                    }
                }
            }
        }
        return matchDp[s.size()][p.size()];

    }
};