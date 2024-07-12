/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxDepth(root *TreeNode) int {
    if root == nil {
        return 0
    }

    leftTreeDepth := maxDepth(root.Left)
    rightTreeDepth := maxDepth(root.Right)
    
    return 1 + max(leftTreeDepth , rightTreeDepth)
    
}
