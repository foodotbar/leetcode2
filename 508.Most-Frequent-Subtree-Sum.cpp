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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> sum,ret;
        if(!root)
            return ret;
        inorder(root,sum);
        unordered_map<int,int> m;
        int maxCounter=0;
        for(int i=0;i<sum.size();i++){
            ++m[sum[i]];
            maxCounter=max(maxCounter,m[sum[i]]);
        }
        for(auto &x:m){
            if(x.second==maxCounter)
                ret.push_back(x.first);
        }
        return ret;
    }
    int inorder(TreeNode* root,vector<int> &sum){
        if(!root)
            return 0;
        root->val+=(inorder(root->left,sum)+inorder(root->right,sum));
        sum.push_back(root->val);
        return root->val;
    }
};

/*

class Solution {
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> sum,ret;
        unordered_map<int,int> m;
        int maxCounter=0;
        inorder(root,m,maxCounter,sum);
        for(auto &x:m){
            if(x.second==maxCounter)
                ret.push_back(x.first);
        }
        return ret;
    }
    int inorder(TreeNode* root,unordered_map<int,int> &m, int &maxCounter,vector<int> &sum){
        if(!root)
            return 0;
        root->val+=(inorder(root->left,m,maxCounter,sum)+inorder(root->right,m,maxCounter,sum));
        sum.push_back(root->val);
        ++m[root->val];
        maxCounter=max(maxCounter,m[root->val]);
        return root->val;
    }
};

*/
