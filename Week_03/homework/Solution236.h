//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION236_H
#define TEST_C___SOLUTION236_H

#include <iostream>
using namespace std;
class Solution236 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root->val == p->val || root->val == q->val) { return root; }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        return left == NULL ? right : right == NULL ? left : root;
    }

};


#endif //TEST_C___SOLUTION236_H
