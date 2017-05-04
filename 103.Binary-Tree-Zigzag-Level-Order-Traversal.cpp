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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        bool zig=false;
        vector<int> level;
        while(!q.empty()){
            int n=q.size();
            level.clear();
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                level.push_back(node->val);
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
            if(zig)
                reverse(level.begin(),level.end());
            zig=(!zig);
            ret.push_back(level);
        }
        return ret;
    }
};
