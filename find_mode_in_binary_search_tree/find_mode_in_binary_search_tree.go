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
	_, res = inOrder(root, prev, &cnt, &max, res)

	return res
}

func inOrder(root, prev *TreeNode, cnt, max *int, res []int) (*TreeNode, []int) {
	if root == nil {
		return nil, res
	}

	prev, res = inOrder(root.Left, prev, cnt, max, res)

	if prev != nil {
		if prev.Val == root.Val {
			*cnt++
		} else {
			*cnt = 1
		}
	}

	if *cnt >= *max {
		if *cnt > *max {
			res = res[0:]
			*max = *cnt
		}

		res = append(res, root.Val)
	}

	prev = root
	return inOrder(root.Right, prev, cnt, max, res)
}
