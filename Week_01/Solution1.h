//
// Created by lamarzhang on 2020/4/19.
//

#ifndef TEST_C___SOLUTION1_H
#define TEST_C___SOLUTION1_H

#include <vector>
#include <unordered_map>

using namespace std;

class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int, int> count;
        for (int i = 0; i< nums.size(); i++) {
            if(count.find(target - nums[i]) != count.end()) {
                res.push_back(count[target - nums[i]]);
                res.push_back(i);
            } else {
                count.insert(make_pair(nums[i],i));
            }
        }
        return res;
    }
};


#endif //TEST_C___SOLUTION1_H
