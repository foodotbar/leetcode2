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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        inorder(root,ret);
        return ret[k-1];
    }
    void inorder(TreeNode* root,vector<int>& ret){
        if(!root)
            return;
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
};

/*

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty()||cur){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }else{
                cur=s.top();
                ret.push_back(cur->val);
                cur=cur->right;
                s.pop();
            }
        }
        return ret[k-1];
    }
};

*/
