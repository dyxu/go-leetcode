#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int L, int R) {
		if (root == nullptr) return nullptr;
		if (root->val < L) return trimBST(root->right, L, R);
		if (root->val > R) return trimBST(root->left, L, R);
		root->left = trimBST(root->left, L, R);
		root->right = trimBST(root->right, L, R);

		return root;
    }
};

void Traverse(TreeNode *root) {
	if (root == nullptr) {
		return;
	}
	std::queue<TreeNode*> queue;
	queue.push(root);
	while (!queue.empty()) {
		size_t n = queue.size();
		for (size_t i = 0; i < n; i++) {
			root = queue.front();
			queue.pop();
			if (root->left != nullptr) {
				queue.push(root->left);
			}
			if (root->right != nullptr) {
				queue.push(root->right);
			}
			std::cout << root->val << " ";
		}
		std::cout << std::endl;
	}
}

int main(int argc, char *argv[]) {
	Solution s;
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(0);
	root->right = new TreeNode(4);
	root->left->right = new TreeNode(2);
	root->left->right->left = new TreeNode(1);
	root = s.trimBST(root, 1, 3);
	Traverse(root);
    return 0;
}
