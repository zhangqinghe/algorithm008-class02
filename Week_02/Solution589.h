//
// Created by lamarzhang on 2020/4/25.
//

#ifndef TEST_C___SOLUTION589_H
#define TEST_C___SOLUTION589_H

#include <vector>
#include <stack>

using namespace std;

class Solution589 {
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
public:
    vector<int> preorder(Node* root) {
        if (!root) { return vector<int>(); }
        stack<Node *> st;
        st.push(root);
        vector<int> res;
        while (!st.empty()) {
            Node *temp = st.top();
            st.pop();
            for (int i = temp->children.size() - 1; i >= 0; i--) {
                st.push(temp->children[i]);
            }
            res.push_back(temp->val);
        }
        return res;
    }
};


#endif //TEST_C___SOLUTION589_H
