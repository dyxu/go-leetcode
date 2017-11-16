#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
		if (map_.find(val) == map_.end()) {
			nums_.push_back(val);
			map_[val] = nums_.size() - 1;
			return true;
		}

		return false;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
		auto iter = map_.find(val);
		if (iter != map_.end()) {
			int back = nums_.back();
			nums_[iter->second] = back;
			map_[back] = iter->second;
			nums_.pop_back();
			map_.erase(val);
			return true;
		}

		return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
		return nums_[std::rand() % nums_.size()];
    }
private:
	vector<int> nums_;
	unordered_map<int, int> map_;
};
