package diameter_of_binary_tree

// 543. Diameter of Binary Tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func diameterOfBinaryTree(root *TreeNode) int {
	diameter := 0
	helper(root, &diameter)
	return diameter
}

func helper(root *TreeNode, diameter *int) int {
	if root == nil {
		return 0
	}

	left := helper(root.Left, diameter)
	right := helper(root.Right, diameter)

	if left+right > *diameter {
		*diameter = left + right
	}

	if left > right {
		return left + 1
	}

	return right + 1
}
