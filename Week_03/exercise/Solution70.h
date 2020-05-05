//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION70_H
#define TEST_C___SOLUTION70_H

#include <vector>

using namespace std;

class Solution70 {
public:
    int climbStairs(int n) {
        if (n < 3) { return n; }
        int f1 = 1,f2 = 2, f3 = 3;
        for (int i = 3; i < n + 1; ++i) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
    int climbStairs_force(int n) {
        if (n < 3) { return n; }
        vector<int> res(n );
        res[0] = 1;
        res[1] = 1;
        for (int i = 2; i < n; ++i) {
            res[i] = res[i - 1] + res[i - 2];
        }
        return res[n-1];
    }
    int climbStairs_recursion(int n) {
        if (n < 3) return  n;
        return climbStairs_recursion(n - 1) + climbStairs_recursion(n - 2);
    }

    static void  test() {
        Solution70 solution70;
        int res = solution70.climbStairs_recursion(44);
        printf("climbStairs_recursion res:%d", res);
        res = solution70.climbStairs_force(44);
        printf("climbStairs_force res:%d", res);
        res = solution70.climbStairs(44);
        printf("climbStairs res:%d", res);
    }

};

#endif //TEST_C___SOLUTION70_H
