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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return create(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* create(vector<int>& inorder,int iLeft,int iRight,vector<int>& postorder,int pLeft,int pRight){
        if(pLeft>pRight)
            return NULL;
        TreeNode* root=new TreeNode(postorder[pRight]);
        int i;
        for(i=iLeft;i<iRight;i++)
            if(inorder[i]==root->val)
                break;
        root->left=create(inorder,iLeft,i-1,postorder,pLeft,pLeft+i-iLeft-1);
        root->right=create(inorder,i+1,iRight,postorder,pLeft+i-iLeft,pRight-1);
        return root;
    }
};

/*

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)
            return NULL;
        TreeNode *p;
        TreeNode *root;
        stack<TreeNode *> stn;
        root = new TreeNode(postorder.back()); 
        stn.push(root); 
        postorder.pop_back(); 
        while(true){
            if(inorder.back()==stn.top()->val){
                p=stn.top();
                stn.pop(); 
                inorder.pop_back(); 
                if(inorder.size()==0) 
                    break;
                if(stn.size() && inorder.back()==stn.top()->val)
                    continue;
                p->left = new TreeNode(postorder.back()); 
                postorder.pop_back();
                stn.push(p->left);
            }
            else {
                p = new TreeNode(postorder.back());
                postorder.pop_back();
                stn.top()->right = p; 
                stn.push(p); 
            }
        }
        return root;
    }
};

*/
