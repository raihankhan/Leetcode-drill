/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func postorderTraversal(root *TreeNode) []int {
        postorder := []int{}
        var dfs func(node *TreeNode)
        dfs = func(node *TreeNode) {
        if node == nil {
            return
        }
        
        dfs(node.Left)
        dfs(node.Right)
        postorder = append(postorder, node.Val)
    }

    dfs(root)
    
    return postorder
}
