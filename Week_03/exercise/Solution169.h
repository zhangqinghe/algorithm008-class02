//
// Created by lamarzhang on 2020/5/4.
//

#ifndef TEST_C___SOLUTION169_H
#define TEST_C___SOLUTION169_H


#include <vector>
using namespace std;

class Solution169 {
    int count_in_range (vector<int> &nums, int lo, int hi, int target) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if(nums[i] == target) { count++; }
        }
        return count;
    }
    int majority_element_rec(vector<int> &nums, int lo, int hi) {
        if (lo == hi) {
            return nums[lo];
        };
        int mid =  (hi + lo) / 2;
        int leftMajority = majority_element_rec(nums, lo, mid);
        int rightMajority = majority_element_rec(nums, mid + 1, hi);
        if (count_in_range(nums, lo, hi, leftMajority) > (hi - lo + 1) / 2) {
            return leftMajority;
        }
        if (count_in_range(nums, lo, hi, rightMajority) > (hi - lo + 1) / 2) {
            return rightMajority;
        }
        return -1;
    }
public:
    int majorityElement(vector<int>& nums) {
        return majority_element_rec(nums, 0, nums.size() - 1);
    }
    static void test() {
        Solution169 solution169;
        vector<int> nums({3,2,3});
       auto res = solution169.majorityElement(nums);
       printf("Solution169::test\r\n");

    }
};


#endif //TEST_C___SOLUTION169_H
