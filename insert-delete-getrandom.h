#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() { }

    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
		auto iter = map_.find(val);
		bool ok = (iter == map_.end());
		nums_.push_back(val);
		if (ok) {
			map_[val] = unordered_set<int>({static_cast<int>(nums_.size() - 1)});
		} else {
			iter->second.insert(nums_.size() - 1);
		}

		return ok;
    }

    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
		auto iter = map_.find(val);
		if (iter != map_.end()) {
			auto first = iter->second.begin();
			iter->second.erase(first);
			int back = nums_.back();
			nums_[*first] = back;
			auto back_iter = map_.find(back);
			back_iter->second.insert(*first);
			back_iter->second.erase(nums_.size() - 1);
			nums_.pop_back();
			if (iter->second.empty()) {
				map_.erase(iter);
			}

			return true;
		}

		return false;
    }

    /** Get a random element from the collection. */
    int getRandom() {
		return nums_[std::rand() % nums_.size()];
    }
private:
	vector<int> nums_;
	unordered_map<int, unordered_set<int>> map_;

};
