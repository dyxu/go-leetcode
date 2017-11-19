class Solution {
public:
    vector<vector<string>> printTree(TreeNode* root) {
		int height = GetHeight(root), width = std::pow(2, height) - 1;
		vector<vector<string>> res(height, vector<string>(width, ""));
		helper(root, 0, 0, width - 1, res);
		return res;
    }

private:
	int GetHeight(const TreeNode* root) {
		if (!root) return 0;
		return std::max(GetHeight(root->left), GetHeight(root->right)) + 1;
	}
	void helper(TreeNode* root, int level, int left, int right, vector<vector<string>>& res) {
		if (!root) return;
		int mid = (left + right) / 2;
		res[level][mid] = std::to_string(root->val);
		helper(root->left, level + 1, left, mid - 1, res);
		helper(root->right, level + 1, mid + 1, right, res);
	}
};
