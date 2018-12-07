/**
 * LeetCode 938. Given the root node of a binary search tree, return the sum of values of all nodes with value between L and R (inclusive).
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
    int rangeSumBST(TreeNode* root, int L, int R) {
        if(!root)
            return 0;
        int target=root->val;
        if(target>=L&&target<=R)
            return rangeSumBST(root->left,L,R)+target+rangeSumBST(root->right,L,R);
        else if(target>L)
            return rangeSumBST(root->left,L,R);
        else
            return rangeSumBST(root->right,L,R);
    }
};
