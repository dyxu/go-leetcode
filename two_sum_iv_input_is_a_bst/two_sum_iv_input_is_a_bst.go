package two_sum_iv_input_is_a_bst

// 653. Two Sum IV - Input is a BST

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTarget(root *TreeNode, k int) bool {
	set := map[int]struct{}{}
	return help(root, k, set)
}

func help(root *TreeNode, k int, set map[int]struct{}) bool {
	if root == nil {
		return false
	}

	if _, ok := set[k-root.Val]; ok {
		return true
	}

	set[root.Val] = struct{}{}

	return help(root.Left, k, set) || help(root.Right, k, set)
}
