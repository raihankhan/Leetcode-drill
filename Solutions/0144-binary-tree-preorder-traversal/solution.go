/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func preorderTraversal(root *TreeNode) []int {
    preorder := []int{}
    var dfs func(node *TreeNode)
    dfs = func(node *TreeNode) {
        if node == nil {
            return
        }
        
        preorder = append(preorder, node.Val)
        dfs(node.Left)
        dfs(node.Right)
    }

    dfs(root)
    
    return preorder
}
