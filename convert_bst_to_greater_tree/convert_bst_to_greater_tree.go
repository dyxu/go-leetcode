package convert_bst_to_greater_tree

// 538. Convert BST to Greater Tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func helper(root *TreeNode, rightSum *int) {
	if root == nil {
		return
	}

	helper(root.Right, rightSum)
	root.Val += *rightSum
	*rightSum = root.Val
	helper(root.Left, rightSum)
}

func convertBST(root *TreeNode) *TreeNode {
	sum := 0
	helper(root, &sum)
	return root
}
