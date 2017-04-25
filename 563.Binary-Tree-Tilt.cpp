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
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        int ret=0;
        postorder(root,ret);
        return ret;
    }
    int postorder(TreeNode* root, int &ret){
        if(!root)
            return 0;
        int leftsum=postorder(root->left,ret);
        int rightsum=postorder(root->right,ret);
        ret+=abs(leftsum-rightsum);
        return leftsum+rightsum+root->val;
    }
};
