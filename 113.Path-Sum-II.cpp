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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ret;
        vector<int> path;
        DFS(root, sum, ret, path);
        return ret;
    }
    void DFS(TreeNode* root, int sum, vector<vector<int>> &ret,vector<int> &path){
        if(!root)
            return;
        path.push_back(root->val);
        if(sum==root->val&&!root->left&&!root->right)
            ret.push_back(path);
        DFS(root->left, sum-root->val, ret, path);
        DFS(root->right, sum-root->val, ret, path);
        path.pop_back();
    }
};

/*

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<TreeNode*> s;
        TreeNode *cur = root, *pre = NULL;
        int val = 0;
        while (cur || !s.empty()) {
            while (cur) {
                s.push_back(cur);
                val += cur->val;
                cur = cur->left;
            }
            cur = s.back(); 
            if (!cur->left && !cur->right && val == sum) {
                vector<int> v;
                for (auto it : s) {
                    v.push_back(it->val);
                }
                res.push_back(v);
            }
            if (cur->right && cur->right != pre) cur = cur->right;
            else {
                pre = cur;
                val -= cur->val;
                s.pop_back();
                cur = NULL;
            }
        }
        return res;
    }
};

*/
