package main

import "fmt"

func main() {
	root := TreeNode{
		Val:  1,
		Left: nil,
		Right: &TreeNode{
			Val: 2,
			Left: &TreeNode{
				Val:   2,
				Left:  nil,
				Right: nil,
			},
			Right: nil,
		},
	}
	fmt.Printf("%v\n", findMode(&root))
}

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

	p, res := inOrder(root.Left, prev, cnt, max, res)
	if p != nil {
		prev = p
	}

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
		}

		res = append(res, root.Val)
		fmt.Printf("prev=%v, cnt=%d, max=%d, %v\n", prev, *cnt, *max, res)
		*max = *cnt
	}

	p, res = inOrder(root.Right, root, cnt, max, res)
	if p != nil {
		prev = p
	}

	return prev, res

}
