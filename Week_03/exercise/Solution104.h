//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION104_H
#define TEST_C___SOLUTION104_H

#include <iostream>
#include <algorithm>

using namespace std;
class Solution104 {
     struct TreeNode {
             int val;
             TreeNode *left;
             TreeNode *right;
             TreeNode(int x) : val(x), left(NULL), right(NULL) {}
     };
public:
    int maxDepth(TreeNode* root) {
        if (!root) { return 0;}
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};


#endif //TEST_C___SOLUTION104_H
