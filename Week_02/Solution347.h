//
// Created by lamarzhang on 2020/4/26.
//

#ifndef TEST_C___SOLUTION347_H
#define TEST_C___SOLUTION347_H

#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution347 {

    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        unordered_map<int, int> m;
        vector<int> res;
        for (int value : nums) {
            m[value]++;
        }
        for(auto v : m) {
            pq.push(make_pair(v.second, v.first));
            while (pq.size() > k) {
                pq.pop();
            }
        }
        for (int i = 0; i < k; ++i) {
            res.push_back(pq.top().second);
        }
        return res;
    }
};


#endif //TEST_C___SOLUTION347_H
