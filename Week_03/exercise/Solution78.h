//
// Created by lamarzhang on 2020/5/3.
//

#ifndef TEST_C___SOLUTION78_H
#define TEST_C___SOLUTION78_H

#include <vector>
using namespace std;
class Solution78 {
    vector<vector<int>> m_res;
    void  backtrack(vector<int>& nums, int index, vector<int>& path) {
        if (index == nums.size()) {
            m_res.push_back(path);
            return;
        }
        backtrack(nums, index + 1, path)；
        path.push_back(nums[index]);
        backtrack(nums, index + 1, path)；
        path.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size()) return {};
        vector<int> path;
        backtrack(nums, 0, path);
        return m_res;
    }
};


#endif //TEST_C___SOLUTION78_H
