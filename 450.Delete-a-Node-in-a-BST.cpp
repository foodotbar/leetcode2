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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return root;
        if(root->val > key)
            root->left=deleteNode(root->left,key);
        else if(root->val < key)
            root->right=deleteNode(root->right,key);
        else{
            if(!root->left || !root->right)
                root=root->left ? root->left:root->right;
            else{
                TreeNode* cur=root->right;
                while(cur->left)
                    cur=cur->left;
                root->val=cur->val;
                root->right=deleteNode(root->right,cur->val);
            }
        }
        return root;
    }
};

/*

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *cur=root,*pre=NULL;
        while(cur){
            if(cur->val==key)
                break;
            pre=cur;
            if(cur->val > key)
                cur=cur->left;
            else
                cur=cur->right;
        }
        if(!cur)
            return root;
        if(!pre)
            return del(cur);
        if(pre->left&&pre->left->val==key)
            pre->left=del(cur);
        else
            pre->right=del(cur);
        return root;
    }
    TreeNode* del(TreeNode* node){
        if(!node->left&&!node->right)
            return NULL;
        if(!node->left||!node->right)
            return node->left?node->left:node->right;
        TreeNode *pre=node,*cur=node->right;
        while(cur->left){
            pre=cur;
            cur=cur->left;
        }
        node->val=cur->val;
        (pre==node?node->right:pre->left)=cur->right;
        return node;
    }
};

*/
