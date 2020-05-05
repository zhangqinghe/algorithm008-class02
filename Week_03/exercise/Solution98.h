//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION98_H
#define TEST_C___SOLUTION98_H

#include "iostream"
#include "vector";

using namespace std;
class Solution98 {
     struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode(int x) : val(x), left(NULL), right(NULL) {}
        };
     bool helper(TreeNode *root, long long min, long long max) {
         if (!root) { return  true;}
         if (root->val <= min || root->val >= max) { return false;}
         return helper(root->left, min, root->val) && helper(root->right, root->val, max );
     }
public:
    bool isValidBST(TreeNode* root) {
        return helper(root, LONG_MIN, LONG_MAX);
    }
};


#endif //TEST_C___SOLUTION98_H
