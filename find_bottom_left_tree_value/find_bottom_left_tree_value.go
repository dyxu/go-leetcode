package find_bottom_left_tree_value

import (
	"container/list"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findBottomLeftValue(root *TreeNode) int {
	queue := list.New()
	queue.PushBack(root)
	left := 0
	for queue.Len() > 0 {
		n := queue.Len()
		for i := 0; i < n; i++ {
			e := queue.Front()
			queue.Remove(e)
			root = e.Value.(*TreeNode)

			if root.Left != nil {
				queue.PushBack(root.Left)
			}

			if root.Right != nil {
				queue.PushBack(root.Right)
			}

			if i == 0 {
				left = root.Val
			}
		}
	}

	return left
}
