#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> hashmap;
		for (auto num: nums) {
			hashmap[num]++;
		}

		vector<int> res;
		std::priority_queue<std::pair<int, int>> pq;
		for (auto iter = hashmap.begin(); iter != hashmap.end(); ++iter) {
			pq.push(std::make_pair(iter->second, iter->first));
			if (pq.size() > hashmap.size() - k) {
				res.push_back(pq.top().second);
				pq.pop();
			}
		}

		return res;
    }
};
