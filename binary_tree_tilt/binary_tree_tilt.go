package binary_tree_tilt

// 563. Binary Tree Tilt

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findTilt(root *TreeNode) int {
	tilt := 0
	postOrder(root, &tilt)

	return tilt
}

func postOrder(root *TreeNode, tilt *int) int {
	if root == nil {
		return 0
	}

	left := postOrder(root.Left, tilt)
	right := postOrder(root.Right, tilt)

	if right-left > 0 {
		*tilt += right - left
	} else {
		*tilt += left - right
	}

	return left + right + root.Val
}
