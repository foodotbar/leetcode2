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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            for(int i=0,n=que.size();i<n;i++){
                TreeNode* node=que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);
            }
            ret.push_back(level);
        }
        return ret;
    }
};

/*

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        DFS(root,0,ret);
        return ret;
    }
    void DFS(TreeNode* root,int level,vector<vector<int>> &ret){
        if(!root)
            return;
        if(ret.size()==level)
            ret.push_back({});
        ret[level].push_back(root->val);
        if(root->left)
            DFS(root->left,level+1,ret);
        if(root->right)
            DFS(root->right,level+1,ret);
    }
};

*/
