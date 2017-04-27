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
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            ret.push_back(node->val);
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        return ret;
    }
};

/*

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        preorder(root,ret);
        return ret;
    }
    void preorder(TreeNode* root, vector<int> &ret){
        if(!root)
            return;
        ret.push_back(root->val);
        preorder(root->left,ret);
        preorder(root->right,ret);
    }
};

*/
