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
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> s;
        int max=0,cnt=1;
        TreeNode* node=root,*pre=NULL;
        while(!s.empty()||node){
            while(node){
                s.push(node);
                node=node->left;
            }
            node=s.top();
            s.pop();
            if(pre)
                cnt = pre->val==node->val?cnt+1:1;
            if(cnt>=max){
                if(cnt>max)
                    ret.clear();
                ret.push_back(node->val);
                max=cnt;
            }
            if(!pre)
                pre=new TreeNode(node->val);
            else 
                pre->val=node->val;
            node=node->right;
        }
        return ret;
    }
};

/*

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ret;
        int cnt=1,max=0;
        TreeNode* pre=NULL;
        inorder(root,cnt,max,pre,ret);
        return ret;
    }
    void inorder(TreeNode* root,int &cnt,int &max,TreeNode* &pre,vector<int> &ret){
        if(!root)
            return;
        inorder(root->left,cnt,max,pre,ret);
        if(pre)
            cnt = pre->val==root->val?cnt+1:1;
        if(cnt>=max){
            if(cnt>max)
                ret.clear();
            ret.push_back(root->val);
            max=cnt;
        }
        if(!pre)
            pre=new TreeNode(root->val);
        else
            pre->val=root->val;
        inorder(root->right,cnt,max,pre,ret);
    }
};

*/
