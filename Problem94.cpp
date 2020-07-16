//
// Created by mac on 2020/7/16.
//

// 中序遍历

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 // 递归写法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        inorder(root, result);
        return result;
    }
private:
    void inorder(TreeNode* root, vector<int>& result) {
        if (root == NULL) return;
        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }
};

// 迭代写法（巧妙版，好理解，颜色标记法，即第一次出现先只进栈，不输出，第二次才输出)
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
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
                nodeStack.push(curr);
                if (curr->left) nodeStack.push(curr->left);
            }
        }
        return result;
    }
};