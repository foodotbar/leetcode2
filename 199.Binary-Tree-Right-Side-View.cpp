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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        bfs(root,0,ret);
        return ret;
    }
    void bfs(TreeNode* root,int level,vector<int> &ret){
        if(!root)
            return;
        if(ret.size()==level)
            ret.push_back(root->val);
        ret[level]=root->val;
        bfs(root->left,level+1,ret);
        bfs(root->right,level+1,ret);
    }
};

/*

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(i==n-1)
                    ret.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            level++;
        }
        return ret;
    }
};

*/
