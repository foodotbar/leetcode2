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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return create(inorder,0,inorder.size()-1,preorder,0,preorder.size()-1);
    }
    TreeNode* create(vector<int>& inorder,int iLeft,int iRight,vector<int>& preorder,int pLeft,int pRight){
        if(pLeft>pRight)
            return NULL;
        TreeNode* root=new TreeNode(preorder[pLeft]);
        int i;
        for(i=iLeft;i<iRight;i++)
            if(inorder[i]==root->val)
                break;
        root->left=create(inorder,iLeft,i-1,preorder,pLeft+1,pLeft+i-iLeft);
        root->right=create(inorder,i+1,iRight,preorder,pLeft+i+1-iLeft,pRight);
        return root;
    }
};
