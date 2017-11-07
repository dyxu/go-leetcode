#include <map>

using namespace std;

class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
    }

    void insert(string key, int val) {
		mm[key] = val;
    }

    int sum(string prefix) {
		int sum = 0, n = prefix.size();
		for (auto iter = mm.lower_bound(prefix); iter != mm.end() && iter->first.substr(0, n) == prefix; ++iter) {
			sum += iter->second;
		}

		return sum;
    }
private:
	std::map<string, int> mm;
};
