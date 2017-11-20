class AllOne {
public:
    /** Initialize your data structure here. */
    AllOne() { }

    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
		if (!key_map_.count(key)) {
			key_map_[key] = buckets_.insert(buckets_.begin(), {{key}, 0});
		}

		auto next = key_map_[key], curr = next++;
		if (next == buckets_.end() || next->val > curr->val + 1) {
			next = buckets_.insert(next, {{}, curr->val + 1});
		}
		next->keys.insert(key);
		key_map_[key] = next;

		curr->keys.erase(key);
		if (curr->keys.empty()) {
			buckets_.erase(curr);
		}
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
		if (!key_map_.count(key)) {
			return;
		}

		auto prev = key_map_[key], curr = prev--;
		key_map_.erase(key);
		if (curr->val > 1) {
			if (curr == buckets_.begin() || prev->val < curr->val - 1) {
				prev = buckets_.insert(curr, {{}, curr->val - 1});
			}
			prev->keys.insert(key);
			key_map_[key] = prev;
		}

		curr->keys.erase(key);
		if (curr->keys.empty()) {
			buckets_.erase(curr);
		}
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
		return buckets_.empty() ? "": *buckets_.back().keys.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
		return buckets_.empty() ? "": *buckets_.front().keys.begin();
    }
private:
	struct Bucket {
		unordered_set<string> keys;
		int val;
		Bucket(const unordered_set<string>& keys, int val): keys(keys), val(val) {}
	};
	list<Bucket> buckets_;
	unordered_map<string, list<Bucket>::iterator> key_map_;
};
