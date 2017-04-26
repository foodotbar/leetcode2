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
    TreeNode* convertBST(TreeNode* root) {
        int sum=0;
        rightMidLeft(root,sum);
        return root;
    }
    void rightMidLeft(TreeNode* root,int &sum){
        if(!root)
            return;
        rightMidLeft(root->right,sum);
        root->val+=sum;
        sum=root->val;
        rightMidLeft(root->left,sum);
    }
};


/*

class Solution {
public:
    TreeNode* convertBST(TreeNode* root) {
        if(!root)
            return NULL;
        convertBST(root->right);
        root->val+=sum;
        sum=root->val;
        convertBST(root->left);
        return root;
    }
private:
    int sum;
};

*/
