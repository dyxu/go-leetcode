package construct_string_from_binary_tree

import "fmt"
import "strconv"

// 606. Construct String from Binary Tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func tree2str(t *TreeNode) string {
	if t == nil {
		return ""
	}

	if t.Left == nil && t.Right == nil {
		return strconv.Itoa(t.Val)
	}

	if t.Right == nil {
		return fmt.Sprintf("%d(%s)", t.Val, tree2str(t.Left))

	}
	return fmt.Sprintf("%d(%s)(%s)", t.Val, tree2str(t.Left), tree2str(t.Right))
}
