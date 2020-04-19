//
// Created by lamarzhang on 2020/4/19.
//

#ifndef TEST_C___SOLUTION42_H
#define TEST_C___SOLUTION42_H

#include <vector>
#include <stack>

using namespace std;

class Solution42 {
public:
    int trap(vector<int>& height) {
        int ans = 0, current = 0;
        stack<int> st;
        while (current < height.size()) {
            while (!st.empty() && height[current] > height[st.top()]) {
                int top = st.top();
                st.pop();
                if (st.empty()) { break; }
                int distance = current - st.top() - 1;
                int bounded_height = min(height[current], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            }
            st.push(current++);
        }
        return ans;

    }

    int trap_two_point(vector<int>& height) {

    }

    int trap_force(vector<int>& height) {
        int ans = 0;
        for (int i = 1; i < height.size() - 1; ++i) {
            int max_left = 0, max_right = 0;
            for (int j = i; j >= 0 ; --j) {
                max_left = max(max_left, height[i]);
            }
            for (int k = i; k < height.size(); ++k) {
                max_right = max(max_right, height[k]);
            }
            ans += min(max_left, max_right) - height[i];
        }
        return ans;
    }
    int trap_dynamic(vector<int>& height) {
        if (height.size() == 0) { return 0; }
        int ans = 0;
        int size = height.size();
        vector<int> left_max(size), right_max(size);
        left_max[0] = height[0];
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        right_max[size - 1] = height[size - 1];
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        return ans;
    }



    static void test() {
        Solution42 solution42;
        vector<int> params = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        int res = solution42.trap(params);
        printf("res:%d", res);
    }
};


#endif //TEST_C___SOLUTION42_H
