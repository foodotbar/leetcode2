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

/*

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0)
        return NULL;
        stack<int> s;
        stack<TreeNode *> st;
        TreeNode *t,*r,*root;
        int i,j,f;
        f=i=j=0;
        s.push(preorder[i]);
        root = new TreeNode(preorder[i]);
        st.push(root);
        t = root;
        i++;
        while(i<preorder.size()){
            if(!st.empty() && st.top()->val==inorder[j]){
                t = st.top();
                st.pop();
                s.pop();
                f = 1;
                j++;
            }
            else{
                if(f==0){
                    s.push(preorder[i]);
                    t -> left = new TreeNode(preorder[i]);
                    t = t -> left;
                    st.push(t);
                    i++;
                }
                else {
                    f = 0;
                    s.push(preorder[i]);
                    t -> right = new TreeNode(preorder[i]);
                    t = t -> right;
                    st.push(t);
                    i++;
                }
            }
        }
        return root;
    }
};
