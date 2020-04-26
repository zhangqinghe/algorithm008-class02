//
// Created by lamarzhang on 2020/4/25.
//

#ifndef TEST_C___SOLUTION429_H
#define TEST_C___SOLUTION429_H

#include <vector>
#include <queue>

using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution429 {
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return {};
        int lever;
        vector<vector<int>> res;
        queue<Node*> que;
        que.push(root);
        //可以标记层
        while (!que.empty()) {
            int size = que.size();
            vector<int> layer;
            while (size > 0) {
                Node* node = que.front();
                que.pop();
                layer.push_back(node->val);
                for(Node *child : node->children) {
                    que.push(child);
                }
                size--;
            }
            res.push_back(layer);
        }
        return res;
    }
};


#endif //TEST_C___SOLUTION429_H
