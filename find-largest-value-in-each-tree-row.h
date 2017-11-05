class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
		if (root == nullptr) return vector<int>();

		vector<int> res;
		std::queue<TreeNode*> Q;
		Q.push(root);
		while (!Q.empty()) {
			int n = Q.size(), max = numeric_limits<int>::min();
			for (int i = 0; i < n; i++) {
				root = Q.front();
				Q.pop();
				if  (root->val > max) {
					max = root->val;
				}
				if (root->left != nullptr) {
					Q.push(root->left);
				}
				if (root->right != nullptr) {
					Q.push(root->right);
				}
			}
			res.push_back(max);
		}

		return res;
	}
};
