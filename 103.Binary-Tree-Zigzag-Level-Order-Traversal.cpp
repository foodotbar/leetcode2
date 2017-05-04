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

/*

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(!root)
            return ret;
        zigzagTraversal(root,0,false,ret);
        return ret;
    }
    void zigzagTraversal(TreeNode* root,int level,bool zig,vector<vector<int>> &ret){
        if(!root)
            return;
        if(ret.size()==level);
            ret.push_back({});
        if(zig)
            ret[level].insert(ret[level].begin(),root->val);
        else
            ret[level].push_back(root->val);
        if(root->left)
            zigzagTraversal(root->left,level+1,!zig,ret);
        if(root->right)
            zigzagTraversal(root->right,level+1,!zig,ret);
    }
};

*/

/*

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        traverse(root,0,result,true);
        return result;
    }
    void traverse(TreeNode *root,int level,vector<vector<int>> &result,bool left_to_right){
        if (!root) 
            return;
        if (level==result.size())
            result.push_back({});
        if (left_to_right)
            result[level].push_back(root->val);
        else
            result[level].insert(result[level].begin(), root->val);
        traverse(root->left,level+1,result,!left_to_right);
        traverse(root->right,level+1,result,!left_to_right);
    }
};

*/
