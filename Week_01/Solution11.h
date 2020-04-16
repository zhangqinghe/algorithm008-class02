//
// Created by lamarzhang on 2020/4/16.
//

#ifndef TEST_C___SOLUTION11_H
#define TEST_C___SOLUTION11_H


#include <vector>
#include <algorithm>

using namespace std;

class Solution11 {
public:
    int maxArea(vector<int>& height) {
        int res = 0, i = 0, j = height.size() -1;
        while(i < j) {
            res = max (res, (j - i) * (height[j]< height[i] ? height[j--] : height[i++]));
        }
        return res;
    }

    static void test () {
        Solution11 solution;
        vector<int> params({1,8,6,2,5,4,8,3,7});
        solution.maxArea(params);
    }
};


#endif //TEST_C___SOLUTION11_H
