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
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> ret;
        traversal(root,0,ret);
        int maxOdd=0,maxEven=0;
        for(int i=0;i<ret.size();i++){
            if(i%2==0)
                maxOdd+=ret[i];
            else
                maxEven+=ret[i];
        }
        return max(maxOdd,maxEven);
    }
    void traversal(TreeNode* root,int level,vector<int> &ret){
        if(!root)
            return;
        if(level==ret.size())
            ret[level]=0;
        ret[level]+=root->val;
        if(root->left)
            traversal(root->left,level+1,ret);
        if(root->right)
            traversal(root->right,level+1,ret);
    }
};

/*

class Solution {
public:
    int rob(TreeNode* root) {
        int l=0,r=0;
        return tryRob(root,l,r);
    }
    int tryRob(TreeNode* root,int &l,int &r){
        if(!root)
            return 0;
        int ll=0,lr=0,rl=0,rr=0;
        l=tryRob(root->left,ll,lr);
        r=tryRob(root->right,rl,rr);
        return max(root->val+ll+lr+rr+rl,l+r);
    }
};

*/
