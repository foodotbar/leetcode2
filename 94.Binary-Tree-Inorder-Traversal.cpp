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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        inorder(root,ret);
        return ret;
    }
    void inorder(TreeNode* root,vector<int>& ret){
        if(!root)
            return;
        if(root->left)
            inorder(root->left,ret);
        ret.push_back(root->val);
        if(root->right)
            inorder(root->right,ret);
    }
};

/*

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode *> s;
        TreeNode* node=root;
        while(!s.empty()||node){
            while(node){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            ret.push_back(node->val);
            node=node->right;
        }
        return ret;
    }
};

*/
