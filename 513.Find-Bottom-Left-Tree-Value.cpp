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
    int findBottomLeftValue(TreeNode* root) {
        if(!root)
            return 0;
        int ret=root->val,maxdepth=0;
        bfs(root,0,maxdepth,ret);
        return ret;
    }
    void bfs(TreeNode* root, int level,int &maxdepth,int &ret){
        if(!root)
            return;
        if(level>maxdepth){
            maxdepth=level;
            ret=root->val;
        }
        bfs(root->left,level+1,maxdepth,ret);
        bfs(root->right,level+1,maxdepth,ret);
    }
};

/*

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int ret=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size(),counter=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(counter++==0)
                    ret=node->val;
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }
        return ret;
    }
};

*/
