package most_frequent_subtree_sum

// 508. Most Frequent Subtree Sum

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func findFrequentTreeSum(root *TreeNode) []int {
	count := map[int]int{}
	max := 0
	helper(root, count, &max)
	res := []int{}
	for k, v := range count {
		if v == max {
			res = append(res, k)
		}
	}

	return res
}

func helper(root *TreeNode, count map[int]int, max *int) int {
	if root == nil {
		return 0
	}

	left := helper(root.Left, count, max)
	right := helper(root.Right, count, max)
	sum := left + right + root.Val
	count[sum]++
	if count[sum] > *max {
		*max = count[sum]
	}

	return sum
}
