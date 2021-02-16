/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void inorder(TreeNode* root,int &ans,int &k)
    {
        if(root==NULL) return;
        inorder(root->left,ans,k);
        k--;
        if(k==0) ans=root->val;
        inorder(root->right,ans,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans=0;
        inorder(root,ans,k);
        return ans;
    }
};
