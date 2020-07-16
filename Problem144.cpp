//
// Created by mac on 2020/7/16.
//

// 递归法省略，直接颜色标记法，迭代法同P94
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
    vector<int> preorderTraversal(TreeNode* root) {
        if (root==NULL) return {};
        stack<TreeNode*> nodeStack;
        map<TreeNode*, int> nodeMap;
        vector<int> result;
        nodeStack.push(root);
        while (!nodeStack.empty()) {
            TreeNode* curr = nodeStack.top();
            nodeStack.pop();
            if (nodeMap.count(curr)) {
                result.push_back(curr->val);
            } else {
                nodeMap[curr] = 1;
                if (curr->right) nodeStack.push(curr->right);
                if (curr->left) nodeStack.push(curr->left);
                nodeStack.push(curr);
            }
        }
        return result;
    }
};

