#include <iostream>
#include <vector>
#include <set>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
		set<int> mm;
		help(root, mm);
		if (mm.size() <= 1) return -1;
		auto iter = mm.begin();
		std::advance(iter, 1);
		return *iter;
    }

	void help(TreeNode* root, set<int>& mm) {
		if (root == nullptr) return;
		mm.insert(root->val);
		if (root->left != nullptr) help(root->left, mm);
		if (root->right != nullptr) help(root->right, mm);
	}
};
int main(int argc, char *argv[]) {
	Solution s;
    return 0;
}
