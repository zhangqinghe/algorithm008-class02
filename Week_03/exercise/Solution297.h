//
// Created by lamarzhang on 2020/5/2.
//

#ifndef TEST_C___SOLUTION297_H
#define TEST_C___SOLUTION297_H

#include <string>
#include <sstream>

using namespace std;

class Solution297 {
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    void  serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "NULL ";
        }
    }

    TreeNode * deserialize(istringstream &ins) {
        string val;
        ins >> val;
        if (val == "NULL ") {
            return nullptr;
        } else {
            TreeNode *node = new TreeNode(stoi(val));
            node->left = deserialize(ins);
            node->right = deserialize(ins);
            return node;
        }
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return  out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ins(data);
        deserialize(ins);
    }
};


#endif //TEST_C___SOLUTION297_H
