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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> treelist;
        vector<int> vallist;
        inorder(root,treelist,vallist);
        sort(vallist.begin(),vallist.end());
        for(int i=0;i<treelist.size();i++)
            treelist[i]->val=vallist[i];
    }
    void inorder(TreeNode* root,vector<TreeNode*> &treelist,vector<int>& vallist){
        if(!root)
            return;
        inorder(root->left,treelist,vallist);
        treelist.push_back(root);
        vallist.push_back(root->val);
        inorder(root->right,treelist,vallist);
    }
};

/*

class Solution {
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* pre=new TreeNode(INT_MIN);
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left);
        if(first==NULL&&pre->val>=root->val)
            first=pre;
        if(first!=NULL&&pre->val>=root->val)
            second=root;
        pre=root;
        inorder(root->right);
    }
};

*/

/*

class Solution {
    TreeNode* first=NULL;
    TreeNode* second=NULL;
    TreeNode* pre=NULL;
public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
    void inorder(TreeNode* root){
        if(!root)
            return;
        inorder(root->left); //search the left sub-tree
        //in inorder traversal of BST, prev should always have smaller value than current value
        if(pre!=NULL&&pre->val>=root->val){
             //incorrect smaller node is always found as prev node
            if(first==NULL)
                first=pre;
            //incorrect larger node is always found as curr(root) node
            second=root;
        }
        // update the prev node
        pre=root;
        inorder(root->right); //search the right sub-tree
    }
};

*/

/*

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* first=NULL;
        TreeNode* second=NULL;
        TreeNode* curr=root;
        TreeNode* prev=NULL;
        stack<TreeNode*> s;
        while(!s.empty()||curr){
            //visit curr's left subtree
            while(curr){
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            //compare curr's val with prev's val if we have one
            if(prev!=NULL&&curr->val < prev->val){
                if(first==NULL)
                    first=prev;//incorrect smaller node is always found as prev node
                second=curr;//incorrect larger node is always found as curr node
            }
            prev=curr;
            //visit curr's left subtree
            curr=curr->right;
        }
        //recover swaped nodes
        swap(first->val,second->val);
    }
};

*/
