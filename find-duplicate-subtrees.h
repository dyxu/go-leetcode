class Solution {
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
		unordered_map<string, vector<TreeNode*>> mm;
		serialize(root, mm);
		vector<TreeNode*> res;
		for (auto iter = mm.begin(); iter != mm.end(); iter++) {
			if (iter->second.size() > 1) res.push_back(iter->second[0]);
		}

		return res;
    }
private:
	string serialize(TreeNode* root, unordered_map<string, vector<TreeNode*>>& mm) {
		if (!root) return "";
		string encode = "(" + serialize(root->left, mm) + std::to_string(root->val) + serialize(root->right, mm) + ")";
		mm[encode].push_back(root);

		return encode;
	}
};
