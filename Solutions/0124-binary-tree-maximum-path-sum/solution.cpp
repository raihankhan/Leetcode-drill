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
    
    int maxToRoot(TreeNode* node, int* maxSum) {
        if(node == nullptr) {
            return 0;
        }
        int l=maxToRoot(node->left,maxSum);
        int r=maxToRoot(node->right,maxSum);
        if(l<0) l=0;
        if(r<0) r=0;
        *maxSum = max(*maxSum , node->val+l+r);
        return node->val+max(l,r);
    }
    
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxToRoot(root,&maxSum);
        return maxSum;
    }
    
};
