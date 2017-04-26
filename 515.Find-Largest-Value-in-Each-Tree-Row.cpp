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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        int max=INT_MIN;
        dfs(root,0,max,ret);
        return ret;
    }
    void dfs(TreeNode* root,int level,int &max,vector<int> &ret){
        if(!root)
            return;
        if(level==ret.size())
            ret.push_back(INT_MIN);
        if(root->val>ret[level]){
            max=root->val;
            ret[level]=root->val;
        }
        dfs(root->left,level+1,max,ret);
        dfs(root->right,level+1,max,ret);
    }
};

/*

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        dfs(root,0,ret);
        return ret;
    }
    void dfs(TreeNode* root,int level,vector<int> &ret){
        if(!root)
            return;
        if(level==ret.size())
            ret.push_back(root->val);
        ret[level]=max(ret[level],root->val);
        dfs(root->left,level+1,ret);
        dfs(root->right,level+1,ret);
    }
};

*/

/*

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(),rowMax=INT_MIN;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                rowMax=max(rowMax,node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            ret.push_back(rowMax);
        }
        return ret;
    }
};

*/
