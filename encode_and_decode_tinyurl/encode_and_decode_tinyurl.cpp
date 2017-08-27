#include <iostream>
#include <unordered_map>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	Solution() {
		table_ = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
		short2long_.clear();
		long2short_.clear();
		srand(time(NULL));
	}

	string encode(string long_url) {
		if (long2short_.count(long_url)) {
			return "http://tinyurl.com/" + long2short_[long_url];
		}

		int idx = 0;
		string str;
		for (int i = 0; i < 6; i++) {
			str.push_back(table_[rand() % 62]);
		}

		while (long2short_.count(str)) {
			str[idx] = table_[rand() % 62];
			idx = (idx + 1) % 5;
		}

		short2long_[str] = long_url;
		long2short_[str] = str;

		return "http://tinyurl.com/" + str;
	}

	string decode(string short_url) {
		string str = short_url.substr(short_url.find_last_of("/") + 1);

		return short2long_.count(str) ? short2long_[str]: short_url;
	}

private:
	unordered_map<string, string> short2long_;
	unordered_map<string, string> long2short_;
	string table_;
};
