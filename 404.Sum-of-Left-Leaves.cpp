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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||!root->left&&!root->right)
            return 0;
        if(root->left&&!root->left->left&&!root->left->right)
            return root->left->val+sumOfLeftLeaves(root->right);
        return sumOfLeftLeaves(root->left)+sumOfLeftLeaves(root->right);
            
    }
};

/*

class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root||!root->left&&!root->right)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        int ret=0;
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left&&!node->left->left&&!node->left->right)
                ret+=node->left->val;
            if(node->left)
                q.push(node->left);
            if(node->right)
                q.push(node->right);
            }
        return ret;
    }
};

*/
