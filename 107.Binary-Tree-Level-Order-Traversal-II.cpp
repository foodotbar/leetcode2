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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()){
            vector<int> level;
            for(int i=0,n=que.size();i<n;i++){
                TreeNode *node=que.front();
                que.pop();
                level.push_back(node->val);
                if(node->left!=NULL)
                    que.push(node->left);
                if(node->right!=NULL)
                    que.push(node->right);
            }
            ret.insert(ret.begin(),level);
        }
        return ret;
    }
};

/*

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ret;
        levelorder(root,0,ret);
        return vector<vector<int>> (ret.rbegin(),ret.rend());
    }
    void levelorder(TreeNode *root,int level,vector<vector<int>> &ret){
        if(!root)
            return;
        if(ret.size()==level)
            ret.push_back({});
        ret[level].push_back(root->val);
        if(root->left)
            levelorder(root->left,level+1,ret);
        if(root->right)
            levelorder(root->right,level+1,ret);
    }
};

*/
