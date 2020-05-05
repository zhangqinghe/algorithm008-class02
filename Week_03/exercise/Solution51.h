//
// Created by lamarzhang on 2020/5/4.
//

#ifndef TEST_C___SOLUTION51_H
#define TEST_C___SOLUTION51_H

#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

class Solution51 {
    set<int> m_col;
    set<int> m_pie;
    set<int> m_na;
    vector<vector<string>> m_res;

    void _DFS(int n, int row, vector<string> &path) {
        if (n == row) {
            m_res.push_back(path);
            return;
        }
        for (int col = 0; col < n; col++) {
            if (m_col.find(col) != m_col.end() || m_pie.find(row - col) != m_pie.end() || m_na.find(row + col) != m_na.end()) {
                continue;
            } else {
                m_col.insert(col);
                m_pie.insert(row - col);
                m_pie.insert(row + col);
                string info(n, '.');
                info[col] = 'Q';
                path.push_back(info);
                _DFS(n, row + 1, path);
                m_col.erase(col);
                m_pie.erase(row - col);
                m_na.erase(row + col);
                path.pop_back();
            }

        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        if (n <= 0) return {};
        vector<string> path;
        _DFS(n, 0, path);
        return m_res;
    }

    static void test() {
        Solution51 solution51;
        auto res =solution51.solveNQueens(4);
        printf("solution51.solveNQueens");
    }
};


#endif //TEST_C___SOLUTION51_H
