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
    int pathSum(TreeNode* root, int sum) {
        if(!root)
            return 0;
        return preorderSumUp(root, 0, sum) + pathSum(root->left, sum) + pathSum(root->right, sum);
    }
    int preorderSumUp(TreeNode *root, int presum, int &sum){
        if(!root)
            return 0;
        int current=presum+root->val;
        return (current==sum) + preorderSumUp(root->left,current,sum) + preorderSumUp(root->right,current,sum);
    }
};

/*

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        int ret=0;
        vector<TreeNode*> path;
        preorderSumUp(root, sum, 0, ret, path);
        return ret;
    }
    void preorderSumUp(TreeNode* root, int sum, int cursum, int &ret, vector<TreeNode*> &path){
        if(!root)
            return;
        cursum+=root->val;
        path.push_back(root);
        if(cursum==sum)
            ret++;
        int tmp=cursum;
        for(int i=0;i<path.size()-1;i++){
            tmp-=path[i]->val;
            if(tmp==sum)
                ret++;
        }
        preorderSumUp(root->left, sum, cursum, ret, path);
        preorderSumUp(root->right, sum, cursum, ret, path);
        path.pop_back();
    }
};

*/

/*

class Solution {
public:
    int pathSum(TreeNode* root, int sum) {
        unordered_map<int, int> m;
        m[0] = 1;
        return preorder(root, sum, 0, m);
    }
    int preorder(TreeNode* node, int sum, int cursum, unordered_map<int, int>& m) {
        if (!node) 
            return 0;
        cursum += node->val;
        int res = m[cursum - sum];
        ++m[cursum];
        res += preorder(node->left, sum, cursum, m) + preorder(node->right, sum, cursum, m);
        --m[cursum];
        return res;
    }
};

*/
