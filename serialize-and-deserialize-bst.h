class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
		string order;
		preOrder(root, order);
		return order;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
		int pos = 0;
		return build(data, pos, std::numeric_limits<int>::min(), std::numeric_limits<int>::max());
    }

private:
	void preOrder(TreeNode* root, string& order) {
		if (!root) return;
		char buf[4];
		std::memcpy(buf, &(root->val), sizeof(int));
		for (int i = 0; i < 4; i++) order.push_back(buf[i]);
		preOrder(root->left, order);
		preOrder(root->right, order);
	}

	TreeNode* build(const string& series, int& pos, int min_value, int max_value) {
		if (pos >= series.size()) return NULL;
		int val;
		memcpy(&val, &series[pos], sizeof(int));
		if (val < min_value || val > max_value) return NULL;
		TreeNode* node = new TreeNode(val);
		pos += sizeof(int);
		node->left = build(series, pos, min_value, val);
		node->right = build(series, pos, val, max_value);

		return node;
	}
};
