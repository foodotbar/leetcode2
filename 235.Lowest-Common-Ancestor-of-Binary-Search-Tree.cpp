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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        if(root->val > max(p->val,q->val))
            return lowestCommonAncestor(root->left,p,q);
        else if(root->val < min(p->val,q->val))
            return lowestCommonAncestor(root->right,p,q);
        else
            return root;
    }
};

/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (true) {
            if (root->val > max(p->val, q->val)) root = root->left;
            else if (root->val < min(p->val, q->val)) root = root->right;
            else break;
        }      
        return root;
    }
};

*/


/*

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur=root;
        while (true) {
            if (cur->val > max(p->val, q->val)) cur = cur->left;
            else if (cur->val < min(p->val, q->val)) cur = cur->right;
            else return cur;
        }      
    }
};

*/
