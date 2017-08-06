package subtree_of_another_tree

// 572. Subtree of Another Tree

// Definition for a binary tree node.
type TreeNode struct {
	Val   int
	Left  *TreeNode
	Right *TreeNode
}

func isSubtree(s *TreeNode, t *TreeNode) bool {
	return s != nil && (equals(s, t) || isSubtree(s.Left, t) || isSubtree(s.Right, t))
}

func equals(s *TreeNode, t *TreeNode) bool {
	if s == nil && t == nil {
		return true
	}

	if s == nil || t == nil {
		return false
	}

	return s.Val == t.Val && equals(s.Left, t.Left) && equals(s.Right, t.Right)
}
