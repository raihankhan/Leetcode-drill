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
    //Return value - Description
    //0 - node don't have camera(0) and is not being watched(0) total 0.
    //1 - node don't have camera(0) and is being watched(1) total 1.
    //2 - node has camera(1) and is being watched(1) total 2.
    int totalCam;
    int cover(TreeNode* curr) {
        if(curr == NULL) {
            return 1;
        }
        int left = cover(curr->left);
        int right = cover(curr->right);
        
        if(left==0 or right==0) {
            totalCam++;
            return 2;
        }
        
        if(left==2 or right==2) {
            return 1;
        }
        
    
        return 0;
        
    }
    
    int minCameraCover(TreeNode* root) {
        if(cover(root)==0) totalCam++;
        return totalCam;
    }
};
