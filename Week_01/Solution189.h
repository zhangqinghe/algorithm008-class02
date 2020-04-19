//
// Created by lamarzhang on 2020/4/19.
//

#ifndef TEST_C___SOLUTION189_H
#define TEST_C___SOLUTION189_H

#include <vector>

using namespace std;

class Solution189 {
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        int count = 0;
        for(int start = 0; count < nums.size(); start++) {
            int current = start;
            int prev = nums[current];
            do {
                int temp = nums[(current +k) % nums.size()];
                nums[(current +k) % nums.size()] = prev;
                prev = temp;
                current = (current +k) % nums.size();
                count++;
            } while (current != start);
        }

    }
};


#endif //TEST_C___SOLUTION189_H
