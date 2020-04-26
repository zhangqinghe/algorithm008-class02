//
// Created by lamarzhang on 2020/4/25.
//

#ifndef TEST_C___SOLUTION144_H
#define TEST_C___SOLUTION144_H


#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution144 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
public:
//    vector<int> ans;
//    vector<int> preorderTraversal(TreeNode* root) {
//        if (root) {
//            ans.push_back(root->val);
//            preorderTraversal(root->left);
//            preorderTraversal(root->right);
//        }
//        return ans;
//    }
    vector<int> preorderTraversal(TreeNode* root) {
        if (!root) { return vector<int>();}
        vector<int> ans;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *cur = st.top();
            st.pop();
            ans.push_back(cur->val);
            if (cur->right) {
                st.push(cur->right);
            }
            if (cur->left) {
                st.push(cur->left);
            }
        }
        return ans;
    }

    vector<int> postOrderIteration(TreeNode* root) {
        if (!root) { return vector<int>(); }
        vector<int> ans;
        TreeNode *cur = root;
        stack<TreeNode *> st;
        st.push(cur);
        while (!st.empty()) {
            TreeNode * peek = st.top();
            if (peek->left && peek->right != cur && peek->left != cur) {
                st.push(peek->left);
            } else if (peek->right && peek->right != cur) {
                st.push(peek->right);
            } else {
                cur = st.top();
                ans.push_back(cur->val);
            }
        }
        return  ans;
    }

};


#endif //TEST_C___SOLUTION144_H
