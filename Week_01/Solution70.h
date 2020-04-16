//
// Created by lamarzhang on 2020/4/16.
//

#ifndef TEST_C___SOLUTION70_H
#define TEST_C___SOLUTION70_H


class Solution70 {
public:
    int climbStairs(int n) {
       if (n <= 2) return n;
       int f1 = 1, f2 = 2, f3 = 3;
        for (int i = 3; i < n + 1; ++i) {
            f3 = f1 + f2;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }

    static void test() {
        Solution70 solution70;
        solution70.climbStairs(2);
    }
};


#endif //TEST_C___SOLUTION70_H
