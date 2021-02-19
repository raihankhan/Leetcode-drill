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
    TreeNode* solve(vector<int>in,int l,int r,int &id,vector<int>pre)
    {
        if(l>r or id==pre.size()) return NULL;
        TreeNode* root= new TreeNode(pre[id]);
        cout << id << " " << l << " " << r << endl;
        int inId;
        for(inId=l;inId<=r;inId++)
            if(in[inId]==root->val) break;
        id++;
        root->left=solve(in,l,inId-1,id,pre);
        root->right=solve(in,inId+1,r,id,pre);
        
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int id=0;
        return solve(inorder,0,inorder.size()-1,id,preorder);
    }
};
