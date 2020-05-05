//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION111_H
#define TEST_C___SOLUTION111_H

#include <iostream>

using namespace std;

class Solution111 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        int minLeft = minDepth(root);
        int minRight = minDepth(root);
        return minLeft == 0 || minRight == 0 ? (minLeft + minRight + 1) : min(minLeft, minRight) + 1;
    }
};


#endif //TEST_C___SOLUTION111_H
