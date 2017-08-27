package maximum_binary_tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func constructMaximumBinaryTree(nums []int) *TreeNode {
	if len(nums) <= 0 {
		return nil
	}

	idx, max := 0, nums[0]
	for i := 1; i < len(nums); i++ {
		if nums[i] > max {
			max = nums[i]
			idx = i
		}
	}

	root := &TreeNode{max, nil, nil}
	root.Left = constructMaximumBinaryTree(nums[:idx])
	root.Right = constructMaximumBinaryTree(nums[idx+1:])

	return root
}
