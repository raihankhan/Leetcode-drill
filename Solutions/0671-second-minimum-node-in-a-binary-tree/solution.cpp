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
    long int check(TreeNode* root,int a)
    {
        if(root==NULL) return LONG_MAX;
        long int ret = min( check(root->left,a), check(root->right,a) );
        if(root->val!=a) ret = min(ret,long(root->val));
        return ret;
    }
    int findSecondMinimumValue(TreeNode* root) {
        int a=root->val;
        long int b=check(root,a);
        if(b==a or b==LONG_MAX) return -1;
        return b;
        
    }
};
