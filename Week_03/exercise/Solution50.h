//
// Created by lamarzhang on 2020/5/3.
//

#ifndef TEST_C___SOLUTION50_H
#define TEST_C___SOLUTION50_H

#include <vector>
using namespace std;
class Solution50 {
    double  fastPow(double x, long long n) {
        if (n == 0) return 1;
        double half = fastPow(x, n/2);
        return n % 2 == 0 ? half * half : half * half * x;
    }
public:
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }

    static void  test() {
        Solution50 solution50;
        auto res = solution50.myPow(2.10000, 3);
        printf("solution50::myPow\r\n");
    }
};


#endif //TEST_C___SOLUTION50_H
