//
// Created by lamarzhang on 2020/4/13.
//

#ifndef TEST_C___SOLUTION283_H
#define TEST_C___SOLUTION283_H

#include <vector>

using namespace std;

class Solution283 {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] != 0) {
                nums[j++] = nums[i];
            }
        }
        for (;j<nums.size();j++) {
            nums[j] = 0;
        }
    }
};


#endif //TEST_C___SOLUTION283_H
