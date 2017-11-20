class LFUCache {
public:
    LFUCache(int capacity): capacity_(capacity) { }

    int get(int key) {
		auto iter = map_.find(key);
		if (iter == map_.end()) {
			return -1;
		}

		KV* kv = *iter->second;
		list_.erase(iter->second);
		iter->second = list_.insert(list_.begin(), kv);

		return kv->value;
    }

    void put(int key, int value) {
		auto iter = map_.find(key);
		if (iter == map_.end()) {
			auto front = list_.insert(list_.begin(), new KV(key, value));
			map_[key] = front;
			if (list_.size() > capacity_) {
				KV* kv = list_.back();
				list_.pop_back();
				map_.erase(kv->key);
			}
		} else {
			KV* kv = *iter->second;
			kv->value = value;
			list_.erase(iter->second);
			iter->second = list_.insert(list_.begin(), kv);
		}
    }
private:
	struct KV {
		int key;
		int value;
		KV(int key, int value): key(key), value(value) { }
	};
	int capacity_;
	list<KV*> list_;
	unordered_map<int, list<KV*>::iterator> map_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
