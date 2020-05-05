//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION22_H
#define TEST_C___SOLUTION22_H


#include <vector>
#include <string>
using namespace std;
class Solution22 {
private:
    vector<string> m_Res;
    void _gen(int left, int right, int n, string str) {
        if (left == n && right == n) {
            m_Res.push_back(str);
        };
        if (left < n) {
            _gen(left + 1, right, n, str + "(");
        }
        if (right < left && right < n) {
            _gen(left, right + 1, n, str + ")");
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        _gen(0, 0, n, "");
        return m_Res;
    }
};


#endif //TEST_C___SOLUTION22_H
