//
// Created by lamarzhang on 2020/4/26.
//

#ifndef TEST_C___SOLUTION264_H
#define TEST_C___SOLUTION264_H


#include <vector>

using namespace std;
class Solution264 {
    int nthUglyNumber(int n) {
        vector<int> dp(n, 1);
        int p2 = 0, p3 = 0, p5 = 0;
        for (int i = 1; i < n; ++i) {
            dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5] *5);
            if (dp[i] == dp[p2] * 2) { p2++; }
            if (dp[i] == dp[p3] * 3) { p3++; }
            if (dp[i] == dp[p5] * 5) { p5++; }
        }
        return dp[n-1];
    }
};


#endif //TEST_C___SOLUTION264_H
