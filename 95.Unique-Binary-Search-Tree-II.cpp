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

/*

class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n==0)
            return {};
        return createTree(1,n);
    }
    vector<TreeNode*> createTree(int left,int right){
        vector<TreeNode*> ret;
        if(left>right){
            ret.push_back(NULL);
            return ret;
        }
        for(int k=left;k<=right;k++){
            vector<TreeNode*> leftTree=createTree(left,k-1);
            vector<TreeNode*> rightTree=createTree(k+1,right);
            for(int i=0;i<leftTree.size();i++){
                for(int j=0;j<rightTree.size();j++){
                    TreeNode* root=new TreeNode(k);
                    root->left=leftTree[i];
                    root->right=rightTree[j];
                    ret.push_back(root);
                }
            }
        }
        return ret;
    }
};

*/
