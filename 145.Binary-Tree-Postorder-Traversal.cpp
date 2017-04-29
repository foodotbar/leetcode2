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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        postorder(root,ret);
        return ret;
    }
    void postorder(TreeNode* root,vector<int>& ret){
        if(!root)
            return;
        postorder(root->left,ret);
        postorder(root->right,ret);
        ret.push_back(root->val);
    }
};

/**** non-recursive way

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ret;
        if(!root)
            return ret;
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* head=root;
        while(!s.empty()){
            TreeNode* top=s.top();
            if((!top->left&&!top->right)||top->right==head||top->left==head){
                ret.push_back(top->val);
                s.pop();
                head=top;
            }else{
                if(top->right)
                    s.push(top->right);
                if(top->left)
                    s.push(top->left);
            }
        }
        return ret;
    }
};

*/
