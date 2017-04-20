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
    bool isSymmetric(TreeNode *root) {
        if (!root) return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode *left, TreeNode *right) {
        if (!left && !right) return true;
        if (left && !right || !left && right || left->val != right->val) return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

/*

class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        if (!root) 
            return true;
        queue<TreeNode*> q1, q2;
        q1.push(root->left);
        q2.push(root->right);
        while (!q1.empty() && !q2.empty()) {
            TreeNode *left = q1.front();
            TreeNode *right = q2.front();
            q1.pop();
            q2.pop();
            if((left && !right) || (!left && right)) 
                return false;
            if (left) {
                if (left->val != right->val) 
                    return false;
                q1.push(left->left);
                q1.push(left->right);
                q2.push(right->right);
                q2.push(right->left);
            }
        }
        return true;
    }
};

*/
