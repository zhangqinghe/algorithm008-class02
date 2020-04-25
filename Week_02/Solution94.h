//
// Created by lamarzhang on 2020/4/25.
//

#ifndef TEST_C___SOLUTION94_H
#define TEST_C___SOLUTION94_H

#include <vector>

 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


using namespace std;

class Solution94 {
public:
    vector<int> ans;
    vector<int> inorderTraversal(TreeNode* root) {
        if (root) {
            inorderTraversal(root->left);
            ans.push_back(root->val);
            inorderTraversal(root->left);
        }
        return ans;
    }
};


#endif //TEST_C___SOLUTION94_H
