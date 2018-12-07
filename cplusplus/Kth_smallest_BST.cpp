/**
 * Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        int r=getRank(root);
        if(r==k-1)
            return root->val;
        else if(r>k-1)
            return kthSmallest(root->left,k);
        else
            return kthSmallest(root->right,k-r-1);
    }
    int getRank(TreeNode* root){
       if(!root)
           return 0;
        else 
            return Size(root->left);
    }
    int Size(TreeNode* root){
        if(!root)
            return 0;
        return Size(root->left)+Size(root->right)+1;
    }
};
