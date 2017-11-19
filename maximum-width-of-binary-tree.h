class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
		if (!root) return 0;
		int max_width = 0;
		queue<pair<TreeNode*, int>> q; // <root, id>
		q.push(std::make_pair(root, 1));
		while (!q.empty()) {
			int left = q.front().second, right = left, n = q.size();
			for (int i = 0; i < n; i++) {
				root = q.front().first;
				right = q.front().second;
				q.pop();
				if (root->left) {
					q.push(std::make_pair(root->left, 2 * right));
				}
				if (root->right) {
					q.push(std::make_pair(root->right, 2 * right + 1));
				}
			}
			max_width = std::max(max_width, right - left + 1);
		}

		return max_width;
    }
};
