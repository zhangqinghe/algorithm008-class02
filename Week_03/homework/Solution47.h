//
// Created by lamarzhang on 2020/5/3.
//

#ifndef TEST_C___SOLUTION47_H
#define TEST_C___SOLUTION47_H

#include <vector>
#include <deque>
using namespace std;
class Solution47 {
    vector<vector<int>> m_Res;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) { return {};}
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtrack(nums, used, path);
        return m_Res;
    }

    void backtrack(vector<int>& nums, vector<bool> &used, vector<int> &path) {
        if (path.size() == nums.size()) {
            m_Res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) { continue; }
            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums,, used, path);
            used[i] = false;
            path.pop_back();
        }
    }
};


#endif //TEST_C___SOLUTION47_H
