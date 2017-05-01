/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root)
            return;
        queue<TreeLinkNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            TreeLinkNode* pre=NULL;
            for(int i=0;i<n;i++){
                TreeLinkNode* cur=q.front();
                q.pop();
                cur->next=pre;
                pre=cur;
                if(cur->right)
                    q.push(cur->right);
                if(cur->left)
                    q.push(cur->left);
            }
        }
    }
};

/*

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) 
            return;
        TreeLinkNode *start=root,*cur=NULL;
        while(start->left){
            cur = start;
            while(cur){
                cur->left->next=cur->right;
                if (cur->next) 
                    cur->right->next=cur->next->left;
                cur=cur->next;
            }
            start=start->left;
        }
    }
};

*/
