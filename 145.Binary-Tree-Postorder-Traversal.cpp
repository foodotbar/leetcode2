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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(root,ret);
        return ret;
    }
    void postorder(TreeNode* root,vector<int>& ret){
        if(!root)
            return;
        postorder(root->left,ret);
        postorder(root->right,ret);
        ret.push_back(root->val);
    }
};
