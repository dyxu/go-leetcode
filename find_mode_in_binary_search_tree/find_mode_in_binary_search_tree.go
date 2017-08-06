package find_mode_in_binary_search_tree

// 501. Find Mode in Binary Search Tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findMode(root *TreeNode) []int {
	res := []int{}
	cnt, max := 1, 0
	var prev *TreeNode
	inOrder(root, &prev, &cnt, &max, &res)

	return res
}

func inOrder(root *TreeNode, prev **TreeNode, cnt, max *int, res *[]int) {
	if root == nil {
		return
	}

	if prev != nil && *prev != nil {
		if (*prev).Val == root.Val {
			*cnt++
		} else {
			*cnt = 1
		}
	}

	inOrder(root.Left, prev, cnt, max, res)
	if *cnt >= *max {
		if *cnt > *max {
			res = &[]int{}
		}

		*res = append(*res, root.Val)
		max = cnt
	}

	*prev = root
	inOrder(root.Right, prev, cnt, max, res)
}
