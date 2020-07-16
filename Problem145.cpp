//
// Created by mac on 2020/7/16.
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
// 也可以先押入一个nullptr空指针表示这是第二次访问，不用使用map或者重新定义结构体添加颜色属性了
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
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
                nodeStack.push(curr);
                if (curr->right) nodeStack.push(curr->right);
                if (curr->left) nodeStack.push(curr->left);
            }
        }
        return result;
    }
};

