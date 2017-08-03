package average_of_levels_in_binary_tree

// 637. Average of Levels in Binary Tree

import (
	"container/list"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func averageOfLevels(root *TreeNode) []float64 {
	queue := list.New()
	res := []float64{}

	queue.PushBack(root)

	for queue.Len() > 0 {
		n := queue.Len()

		sum := 0.0
		for i := 0; i < n; i++ {
			ele := queue.Front()
			queue.Remove(ele)
			root = ele.Value.(*TreeNode)

			sum += float64(root.Val)
			if root.Left != nil {
				queue.PushBack(root.Left)
			}

			if root.Right != nil {
				queue.PushBack(root.Right)
			}
		}

		res = append(res, sum/float64(n))
	}

	return res
}
