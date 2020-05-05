//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION105_H
#define TEST_C___SOLUTION105_H

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution105 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };
    TreeNode *helper(vector<int>& preorder, int pStart, int pEnd,vector<int>& inorder, int iStart, int iEnd) {
        if (pStart > pEnd || iStart >iEnd) { return NULL; }
        TreeNode *root = new TreeNode(preorder[pStart]); //重建根节点
        int index = 0; //寻找 根节点在中序遍历的问题
        while (inorder[iStart + index] != preorder[pStart]) { index++; }
        root->left = helper(preorder, pStart + 1, pStart + index, inorder, iStart, iStart + index -1);
        root->right = helper(preorder, pStart + index + 1, pEnd, inorder, iStart + index -1, iEnd);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) { return NULL; }
        return helper(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};


#endif //TEST_C___SOLUTION105_H
