//
// Created by lamarzhang on 2020/4/25.
//

#ifndef TEST_C___SOLUTION590_H
#define TEST_C___SOLUTION590_H


#include <vector>
#include <stack>

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution590 {
public:
    vector<int> postorder(Node *root) {
        if (!root) { return vector<int>(); }
        vector<int> ans;
        stack<Node *> st;
        while (!st.empty()) {
            Node *temp = st.top();
            st.pop();
            for (int i = 0; i < root->children.size(); ++i) {
                st.push(root->children[i]);
            }
            ans.push_back(temp->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};


#endif //TEST_C___SOLUTION590_H
