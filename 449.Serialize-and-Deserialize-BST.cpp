/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root,out);
        return out.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

private:

    void serialize(TreeNode* root,ostringstream &out){
        if(root){
            out << root->val << ' ';
            serialize(root->left,out);
            serialize(root->right,out);
        }else
            out << "#" << ' ';
    }
    
    TreeNode* deserialize(istringstream& in){
        string tmp;
        in >> tmp;
        if(tmp=="#")
            return nullptr;
        TreeNode* root=new TreeNode(stoi(tmp));
        root->left=deserialize(in);
        root->right=deserialize(in);
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));


/*

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string out;
        preorder(root,out);
        return out;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int pos=0;
        return reconstruct(data,pos,INT_MIN,INT_MAX);
    }

private:

    void preorder(TreeNode* root,string &out){
        if(!root)
            return;
        char buf[4];
        memcpy(buf,&root->val,sizeof(int)); //burn the int into 4 chars
        for(int i=0;i<4;i++)
            out.push_back(buf[i]);
        preorder(root->left,out);
        preorder(root->right,out);
    }

    TreeNode* reconstruct(const string& data,int& pos, int min,int max){
        if(pos>=data.size())
            return NULL; //using pos to check whether buffer ends is better than using char* directly.
        int value;
        memcpy(&value,&data[pos],sizeof(int));
        if(value<min||value>max)
            return NULL;
        TreeNode* root=new TreeNode(value);
        pos += sizeof(int);
        root->left=reconstruct(data,pos,min,value);
        root->right=reconstruct(data,pos,value,max);
        return root;
    }
};


// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

*/
