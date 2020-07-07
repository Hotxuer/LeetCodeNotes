//
// Created by mac on 2020/7/7.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return findSum(root, sum);
    }
private:
    bool findSum(TreeNode* root, int sum) {
        if (root==NULL) return false;
        int val = root->val;
        if (root->left==NULL && root->right==NULL)
            return val == sum;
        return findSum(root->left, sum-val) || findSum(root->right, sum-val);

    }
};