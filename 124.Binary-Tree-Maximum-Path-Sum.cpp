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
    int maxPathSum(TreeNode* root) {
        if(!root)
            return 0;
        int ret=root->val;
        maxPathSumDFS(root,ret);
        return ret;
    }
    int maxPathSumDFS(TreeNode* root,int& ret){
        if(!root)
            return 0;
        int left=maxPathSumDFS(root->left,ret);
        int right=maxPathSumDFS(root->right,ret);
        int top=root->val+(left>0?left:0)+(right>0?right:0);
        ret=max(ret,top);
        return max(left,right)>0?max(left,right)+root->val:root->val;
    }
};
