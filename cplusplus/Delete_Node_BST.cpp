/**
 * LeetCode 450. Given a root node reference of a BST and a key, 
 * delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
static int pr = []() { 
        std::ios::sync_with_stdio(false); 
        cin.tie(NULL);  
        return 0; 
    }();
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
       del(root,key);
        return root;
    }
    void del(TreeNode*& root,int key){
        if(!root)
            return;
        int val=root->val;
        if(val<key)
            return del(root->right,key);
        else if(val>key)
            return del(root->left,key);
        else{
            if((!root->left)&&(!root->right)){
                delete root;
                root=nullptr;
            }
            else if((!root->left)||(!root->right)){
                TreeNode* tmp=root;
                if(!root->left)
                    root=root->right;
                else
                    root=root->left;
                delete tmp;
            }
            else{
                TreeNode*&t=findmax(root->left);
                root->val= t->val;
                TreeNode*tmp=t;
                t=t->left;
                delete tmp;
            }
        }
    }
    TreeNode*& findmax(TreeNode*& root){
        if(!root->right)
            return root;
        else
            return findmax(root->right);
    }
};
