class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
		if (!root) return 0;
		int res = 0;
		helper(root, res);

		return res;
    }
private:
	int helper(TreeNode* root, int& res) {
		if (!root) return 0;
		int left = helper(root->left, res);
		int right = helper(root->right, res);
		left = (root->left && root->val == root->left->val) ? left + 1: 0;
		right = (root->right && root->val == root->right->val) ? right + 1: 0;
		res = std::max(res, left + right);

		return std::max(left, right);
	}
};
