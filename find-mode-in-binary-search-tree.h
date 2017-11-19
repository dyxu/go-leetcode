class Solution {
public:
    vector<int> findMode(TreeNode* root) {
		vector<int> result;
		int cnt = 1, max_cnt = 0;
		TreeNode* prev = NULL;
		helper(root, prev, cnt, max_cnt, result);

		return result;
    }

private:
	void helper(TreeNode* root, TreeNode*& prev, int& cnt, int& max_cnt, vector<int>& result) {
		if (!root) return;
		helper(root->left, prev, cnt, max_cnt, result);
		if (prev) {
			cnt = (prev->val == root->val) ? cnt+1: 1;
		}
		if (cnt >= max_cnt) {
			if (cnt > max_cnt) result.clear();
			result.push_back(root->val);
			max_cnt = cnt;
		}
		prev = root;
		helper(root->right, prev, cnt, max_cnt, result);
	}
};
