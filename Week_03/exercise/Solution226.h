//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION226_H
#define TEST_C___SOLUTION226_H

#include <queue>
#include "iostream"
using namespace std;

class Solution226 {
     struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) { return NULL; }
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        root->right = left;
        root->left = right;
        return root;
    }
    TreeNode* invertTree_BFS(TreeNode* root) {
        if (!root) { return NULL; }
        queue<TreeNode *> queue;
        queue.push(root);
        while (queue.size()) {
            TreeNode *node = queue.front();
            queue.pop();
            swap(node->left, node->right);
            if (node->left) { queue.push(node->left); }
            if (node->right) { queue.push(node->right); }
        }
        return root;
    }


};


#endif //TEST_C___SOLUTION226_H
