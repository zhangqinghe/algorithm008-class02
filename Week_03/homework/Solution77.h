//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION77_H
#define TEST_C___SOLUTION77_H

#include <vector>
using namespace std;
class Solution77 {
    int m_n;
    int m_k;
    vector<vector<int>> m_output;
    void backtrack(int first, vector<int> &curr) {
        if (curr.size() == m_k) {
            m_output.push_back(curr);
            return;
        }
        for (int i = first; i <= m_n; ++i) {
            curr.push_back(i);
            backtrack(first + 1, curr);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        m_n = n;
        m_k = k;
        vector<int> params;
        backtrack(1, params);
        return  m_output;
    }

    static void test () {
        Solution77 solution77;
        auto res = solution77.combine(4, 2);
        printf("Solution77 combine\r\n");
    }
};


#endif //TEST_C___SOLUTION77_H
