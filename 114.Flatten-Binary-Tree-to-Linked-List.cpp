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
    void flatten(TreeNode* root) {
        TreeNode* cur=root;
        while(cur){
            if(cur->left){
                TreeNode* p=cur->left;
                while(p->right)
                    p=p->right;
                p->right=cur->right;
                cur->right=cur->left;
                cur->left=NULL;
            }
            cur=cur->right;
        }
    }
};
/*
     1
    / \
   2   5
  / \   \
 3   4   6

   1
    \
     2
    / \
   3   4
        \
         5
          \
           6
           
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/

/*

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        if(root->left)
            flatten(root->left);
        if(root->right)
            flatten(root->right);
        TreeNode* tmp=root->right;
        root->right=root->left;
        root->left=NULL;
        while(root->right)
            root=root->right;
        root->right=tmp;
    }
};

     1
    / \
   2   5
  / \   \
 3   4   6

     1
    / \
   2   5
    \   \
     3   6
      \    
       4

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

*/

/*

class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root)
            return;
        stack<TreeNode*> s;
        s.push(root);
        while(!s.empty()){
            TreeNode* node=s.top();
            s.pop();
            if(node->left){
                TreeNode* tmp=node->left;
                while(tmp->right)
                    tmp=tmp->right;
                tmp->right=node->right;
                node->right=node->left;
                node->left=NULL;
            }
            if(node->right)
                s.push(node->right);
        }
    }
};

*/
