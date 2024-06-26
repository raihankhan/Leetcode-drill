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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        //cout << p->val << " " << q->val << endl;
        if(p==nullptr and q==nullptr) return true;
        if(p==nullptr or q==nullptr) return false;
        if(p->val!=q->val) return false;
        
        return isSameTree(p->left,q->left)&isSameTree(p->right,q->right);
        
    }
};
