//
// Created by lamarzhang on 2020/5/4.
//

#ifndef TEST_C___SOLUTION17_H
#define TEST_C___SOLUTION17_H

#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution17 {
    unordered_map<char, string> m_map;
    vector<string> m_res;
    void backtrack(string &digit, int lever, string str) {
        if (lever == digit.size()) {
            m_res.push_back(str);
            return;
        }
        string letter = m_map[digit[lever]];
        for (int i = 0; i < letter.size(); i++) {
            backtrack(digit, lever + 1, str + letter[i]);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        m_map['2'] = "abc";
        m_map['3'] = "def";
        m_map['4'] = "ghi";
        m_map['5'] = "jkl";
        m_map['6'] = "mno";
        m_map['7'] = "pqrs";
        m_map['8'] = "tuv";
        m_map['9'] = "wxyz";
        backtrack(digits, 0, "");
        return m_res;
    }
    static  void  test() {
        Solution17 solution17;
        auto res = solution17.letterCombinations("23");
        printf("Solution17::letterCombinations res");
    }
};


#endif //TEST_C___SOLUTION17_H
