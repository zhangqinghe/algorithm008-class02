//
// Created by lamarzhang on 2020/4/26.
//

#ifndef TEST_C___SOLUTION40_H
#define TEST_C___SOLUTION40_H

#include <vector>
#include <queue>

using namespace std;

class Solution40 {
public:
    //
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        if (arr.size() < k) return {};
        vector<int> res(k);
        priority_queue<int, vector<int>, greater<int> > queue;
        for (int i = 0; i < arr.size(); ++i) {
            queue.push(arr[i]);
        }
        for (int j = 0; j < k; ++j) {
            res[j] = queue.top();
            queue.pop();
        }
        return res;
    }
    //
    static void test() {
        Solution40 solution40;
        vector<int> params({3, 2, 1});
        vector<int> res = solution40.getLeastNumbers(params,2);
        printf("res:");
    }
};


#endif //TEST_C___SOLUTION40_H
