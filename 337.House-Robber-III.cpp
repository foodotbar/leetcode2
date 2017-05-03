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

/*

class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        int tmp=0;
        if(root->left)
            tmp+=rob(root->left->left)+rob(root->left->right);
        if(root->right)
            tmp+=rob(root->right->left)+rob(root->right->right);
        return max(tmp+root->val,rob(root->left)+rob(root->right));
    }
};

*/

/* incorrect answer

class Solution {
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        vector<int> ret;
        traversal(root,0,ret);
        int a=0,b=0;
        for(int i=0;i<ret.size();i++){
            int m=a,n=b;
            a=n+ret[i];
            b=max(m,n);
        }
        return max(a,b);
    }
    void traversal(TreeNode* root,int level,vector<int> &ret){
        if(!root)
            return;
        if(level==ret.size())
            ret.push_back(0);
        ret[level]+=root->val;
        traversal(root->left,level+1,ret);
        traversal(root->right,level+1,ret);
    }
};

*/
