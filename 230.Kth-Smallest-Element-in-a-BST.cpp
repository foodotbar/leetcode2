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
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        inorder(root,ret);
        return ret[k-1];
    }
    void inorder(TreeNode* root,vector<int>& ret){
        if(!root)
            return;
        inorder(root->left,ret);
        ret.push_back(root->val);
        inorder(root->right,ret);
    }
};

/*

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> ret;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty()||cur){
            if(cur){
                s.push(cur);
                cur=cur->left;
            }else{
                cur=s.top();
                ret.push_back(cur->val);
                cur=cur->right;
                s.pop();
            }
        }
        return ret[k-1];
    }
};

*/

/*

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int cnt=0;
        stack<TreeNode*> s;
        TreeNode* cur=root;
        while(!s.empty()||cur){
            while(cur){
                s.push(cur);
                cur=cur->left;
            }
            cur=s.top();
            s.pop();
            ++cnt;
            if(cnt==k)
                return cur->val;
            cur=cur->right;
        }
        return 0;
    }
};

*/

/*

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        return inorder(root,k);
    }
    int inorder(TreeNode* root, int &k){
        if(!root)
            return -1;
        int val=inorder(root->left,k);
        if(!k)
            return val;
        if(!--k)
            return root->val;
        return inorder(root->right,k);
    }
};

*/
