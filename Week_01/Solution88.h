//
// Created by lamarzhang on 2020/4/19.
//

#ifndef TEST_C___SOLUTION88_H
#define TEST_C___SOLUTION88_H

#include <vector>

using namespace std;

class Solution88 {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n -1;
        while (i >=0 && j >= 0) {
            nums1[k--] = nums1[i] > nums2[j] ? nums1[i--] : nums2[j--];
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }

    static void test() {
        Solution88 solution88;
        vector<int> m = {0};
        vector<int> n = {1};
        solution88.merge(m, 0, n, 1);
        printf("test\r\n");
    }
};


#endif //TEST_C___SOLUTION88_H
