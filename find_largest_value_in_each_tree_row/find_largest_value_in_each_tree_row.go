package find_largest_value_in_each_tree_row

import (
	"container/list"
)

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func largestValues(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	res := []int{}
	queue := list.New()
	queue.PushBack(root)
	for queue.Len() > 0 {
		n := queue.Len()
		max := -(1<<32 - 1)
		for n > 0 {
			e := queue.Front()
			queue.Remove(e)
			v := e.Value.(TreeNode).Val
			if v > max {
				max = v
			}
			if 
			n--
		}
		res = append(res, max)
	}

	return res
}
