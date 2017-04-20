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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left&&!root->right)
            return 1;
        return max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

/*

class Solution {
public:
    int maxDepth(TreeNode* root) {
        return !root?0:max(maxDepth(root->left),maxDepth(root->right))+1;
    }
};

*/

/* Breadth-first-search
// Calculate the count of the last level.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        queue<TreeNode*> que;
        que.push(root);
        int ret=0,i,n;
        while(!que.empty()){
            ++ret;
            for(i=0,n=que.size();i<n;i++){
                TreeNode* node=que.front();
                que.pop();
                if(node->left!=NULL)
                    que.push(node->left);
                if(node->right!=NULL)
                    que.push(node->right);
            }
        }
        return ret;
    }
};

*/
