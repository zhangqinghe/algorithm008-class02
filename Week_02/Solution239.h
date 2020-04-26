//
// Created by lamarzhang on 2020/4/18.
//

#ifndef TEST_C___SOLUTION239_H
#define TEST_C___SOLUTION239_H

#include <deque>
#include <vector>

using namespace std;

class Solution239 {
private:
public:
    vector<int> maxSlidingWindow_force(vector<int> &nums, int k) {
        if (nums.size() == 0 || k == 0) { return vector<int>(); }
        int window_size = nums.size() - k + 1;
        vector<int> res(window_size);
        for (int i = 0; i < window_size; ++i) {
            int max = INT_MIN;
            for (int j = i; j < i + k; ++j) {
                if (nums[j] > max) { max = nums[j]; };
            }
            res[i] = max;
        }
        return res;
    }

    vector<int> maxSlidingWindow_priority_queue(vector<int> &nums, int k) {
        if (nums.size() == 0 || k == 0) return {};
        vector<int> res[nums.size() - k +1];
        priority_queue<int> maxPQ;
        for (int i = 0; i < nums.size(); ++i) {
            if (i >= k) {
                //maxPQ.top(); 这里需要从堆中删除元素
            }
            maxPQ.push(nums[i]);
            if (i >= k-1) {
                res[i - k + 1] = maxPQ.top();
            }
        }
        return res;

    }


    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> window;
        vector<int> res;
        for (int i = 0; i < nums.size() ;i++) {
            if (i -0 >= k && i - window.back() >= k) {
                window.pop_back();
            }
            while (!window.empty() && nums[window.front()] < nums[i]) {
                window.pop_front();
            }
            window.push_front(i);
            if (i-0 >= k-1) {
                res.push_back(nums[window.back()]);
            }
        }
        return res;
    }

    static void test() {
        vector<int> params({1, -1});
        Solution239 solution238;
        vector<int> res = solution238.maxSlidingWindow_force(params, 1);
        res = solution238.maxSlidingWindow(params, 1);
    }
};


#endif //TEST_C___SOLUTION239_H
