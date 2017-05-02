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
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        stack<TreeNode*> s;
        TreeNode* cur=root,*pre=NULL;
        while(!s.empty()||cur){
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            TreeNode* node=s.top();
            s.pop();
            if(pre&&node->val<=pre->val)
                return false;
            pre=node;
            cur=node->right;
        }
        return true;
    }
};

/*

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return valid(root,LONG_MIN,LONG_MAX);
    }
    bool valid(TreeNode* root,long small,long big){
        if(!root)
            return true;
        if(root->val<=small||root->val>=big)
            return false;
        return valid(root->left,small,root->val) && valid(root->right,root->val,big);
    }
};

*/

/*

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        vector<int> ret;
        inorder(root,ret);
        for(int i=0;i<ret.size()-1;i++)
            if(ret[i]>=ret[i+1])
                return false;
        return true;
    }
    void inorder(TreeNode* root, vector<int>& ret){
        if(!root)
            return;
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
};

*/

/*

class Solution {
public:
    TreeNode* pre;
    bool isValidBST(TreeNode* root) {
        if(!root)
            return true;
        int ret=1;
        pre=NULL;
        inorder(root,ret);
        if(ret==1)
            return true;
        return false;
    }
    void inorder(TreeNode* root,int &ret){
        if(!root)
            return;
        inorder(root->left,ret);
        if(!pre)
            pre=root;
        else{
            if(root->val<=pre->val)
                ret=0;
            pre=root;
        }
        inorder(root->right,ret);
    }
};

*/
