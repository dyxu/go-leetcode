#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <unordered_set>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 鱼塘抽样算法
// R[1..k] = ReservoirSample(S[1..n])
//   for i = 1 to k:
//     R[i] = S[i]
//   for i = k+1 to n:
//     j = random(1, i)
//     if j <= k
//       R[j] = S[i]
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
		head_ = head;
    }

    /** Returns a random node's value. */
    int getRandom() {
		int res = head_->val, last = 2;
		ListNode* node = head_->next;
		while (node != nullptr) {
			int x =  std::rand() % last;
			if (x == 0) {
				res = node->val;
			}
			last++;
			node = node->next;
		}

		return res;
    }
private:
	ListNode* head_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */
