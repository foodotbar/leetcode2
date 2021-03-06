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
    int sumNumbers(TreeNode* root) {
        vector<int> pathSums;
        if(!root)
            return 0;
        root2leaf(root,0,pathSums);
        int sum=0;
        for(int i=0;i<pathSums.size();i++)
            sum+=pathSums[i];
        return sum;
    }
    void root2leaf(TreeNode* root,int sum,vector<int> &pathSums){
        sum=10*sum+root->val;
        if(!root->left&&!root->right)
            pathSums.push_back(sum);
        else{
            if(root->left)
            root2leaf(root->left,sum,pathSums);
        if(root->right)
            root2leaf(root->right,sum,pathSums);
        }
    }
};

/*

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        return root2leafSum(root,0);
    }
    int root2leafSum(TreeNode* root,int sum){
        if(!root)
            return 0;
        sum=10*sum+root->val;
        if(!root->left&&!root->right)
            return sum;
        return root2leafSum(root->left,sum)+root2leafSum(root->right,sum);
    }
};

*/

/*

class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        stack<TreeNode*> s1;
        stack<int> s2;
        s1.push(root);
        s2.push(root->val);
        int sum=0,ret=0;
        while(!s1.empty()){
            TreeNode* node=s1.top();
            s1.pop();
            sum=s2.top();
            s2.pop();
            if(!node->left&&!node->right){
                ret+=sum;
            }
            if(node->right){
                s1.push(node->right);
                s2.push(node->right->val + 10*sum);
            }
            if(node->left){
                s1.push(node->left);
                s2.push(node->left->val + 10*sum);
            }
        }
        return ret;
    }
};

*/

