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
            TreeLinkNode* pre=NULL;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeLinkNode* node=q.front();
                q.pop();
                node->next=pre;
                pre=node;
                if(node->right)
                    q.push(node->right);
                if(node->left)
                    q.push(node->left);
            }
        }
    }
};

/*

// Non-recursion, constant space
class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (!root) 
            return;
        TreeLinkNode *leftMost = root;
        while (leftMost) {
            TreeLinkNode *p = leftMost;
            while (p && !p->left && !p->right) 
                p = p->next;
            if (!p) 
                return;
            leftMost = p->left ? p->left : p->right;
            TreeLinkNode *cur = leftMost;
            while (p) {
                if (cur == p->left) {
                    if (p->right) {
                        cur->next = p->right;
                        cur = cur->next;
                    }
                    p = p->next;
                }
                else if (cur == p->right) {
                    p = p->next;
                } else {
                    if (!p->left && !p->right) {
                        p = p->next;
                        continue;
                    }
                    cur->next = p->left ? p->left : p->right;
                    cur = cur->next;
                }
            }
        }
    }
};

*/
