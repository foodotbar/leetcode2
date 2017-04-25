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
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        int diameter=0;
        dfs(root,diameter);
        return diameter;
    }
    int dfs(TreeNode* root,int &diameter){
        if(!root)
            return 0;
        int leftdepth=dfs(root->left,diameter);
        int rightdepth=dfs(root->right,diameter);
        diameter=max(diameter,leftdepth+rightdepth);
        return max(leftdepth,rightdepth)+1;
    }
};
