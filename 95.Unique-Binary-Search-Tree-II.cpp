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
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return *dfs(1,n);
    }
    vector<TreeNode*> *dfs(int start, int end){
        vector<TreeNode*> *ret=new vector<TreeNode*>();;
        if(start>end)
            ret->push_back(NULL);
        else{
            for(int i=start;i<=end;i++){
                vector<TreeNode*> *leftSubTrees=dfs(start,i-1);
                vector<TreeNode*> *rightSubTrees=dfs(i+1,end);
                for(int j=0;j<leftSubTrees->size();j++){
                    for(int k=0;k<rightSubTrees->size();k++){
                        TreeNode* node=new TreeNode(i);
                        node->left=(*leftSubTrees)[j];
                        node->right=(*rightSubTrees)[k];
                        ret->push_back(node);
                    }
                }
            }
        }
        return ret;
    }
};
