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
    int countNodes(TreeNode* root) {
        int hLeft=0,hRight=0;
        TreeNode* pLeft=root,*pRight=root;
        while(pLeft){
            hLeft++;
            pLeft=pLeft->left;
        }
        while(pRight){
            hRight++;
            pRight=pRight->right;
        }
        if(hLeft==hRight)
            return pow(2,hLeft)-1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
};

/*

class Solution {
public:
    int countNodes(TreeNode* root) {
        int hLeft=leftHeight(root);
        int hRight=rightHeight(root);
        if (hLeft==hRight) 
            return pow(2, hLeft) - 1;
        return countNodes(root->left)+countNodes(root->right)+1;
    }
    int leftHeight(TreeNode* root) {
        if (!root) 
            return 0;
        return 1+leftHeight(root->left);
    }
    int rightHeight(TreeNode* root) {
        if (!root) 
            return 0;
        return 1+rightHeight(root->right);
    }
};

*/
