//
// Created by lamarzhang on 2020/5/3.
//

#ifndef TEST_C___SOLUTION46_H
#define TEST_C___SOLUTION46_H

#include <vector>
using namespace std;

class Solution46 {
    vector<vector<int>> m_res;
    void backtrack(vector<int>& nums, vector<int> &track) {
        if (track.size() == nums.size()) {
            m_res.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            vector<int>::iterator iter = find(track.begin(), track.end(), nums[i]);
            if (iter != track.end()) { continue; }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return m_res;
    }
    static void test() {
        Solution46 solution46;
        vector<int> params = {1,2,3};
        auto res = solution46.permute(params);
        printf("Solution46::test");
    }
};


#endif //TEST_C___SOLUTION46_H
