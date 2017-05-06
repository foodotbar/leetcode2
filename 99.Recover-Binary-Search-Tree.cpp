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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> treelist;
        vector<int> vallist;
        inorder(root,treelist,vallist);
        sort(vallist.begin(),vallist.end());
        for(int i=0;i<treelist.size();i++)
            treelist[i]->val=vallist[i];
    }
    void inorder(TreeNode* root,vector<TreeNode*> &treelist,vector<int>& vallist){
        if(!root)
            return;
        inorder(root->left,treelist,vallist);
        treelist.push_back(root);
        vallist.push_back(root->val);
        inorder(root->right,treelist,vallist);
    }
};
