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
    TreeNode* solve(vector<int>in,int l,int r,vector<int>&post)
    {
        if(l>r or post.empty()) return NULL;
        TreeNode* root=new TreeNode(post.back());
        int id;
        for(id=l;id<=r;id++)
            if(in[id]==post.back()) break;
        
        post.pop_back();
        root->right=solve(in,id+1,r,post);
        root->left=solve(in,l,id-1,post);
        
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return solve(inorder,0,inorder.size()-1,postorder);
    }
};
