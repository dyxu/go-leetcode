#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
		unordered_set<string> dicts;
		for (auto word: dict) {
			dicts.insert(word);
		}

		std::stringstream res;
		std::stringstream ss(sentence);
		string word;
		while (std::getline(ss, word, ' ')) {
			size_t idx = 0;
			for (;idx < word.size(); idx++) {
				if (dicts.find(word.substr(0, idx)) != dicts.end()) {
					break;
				}
			}
			res << word.substr(0, idx) << " ";
		}

		string ret = res.str();
		ret.pop_back();
		return ret;
    }

	string replaceWords2(vector<string>& dict, string sentence) {
		vector<vector<string>> prefixs(26);
		std::sort(dict.begin(), dict.end(), [](const string& x, const string& y) {
				return x.size() < y.size();
			});
		for (auto word: dict) {
			if (word.empty()) {
				continue;
			}
			prefixs[word[0]-'a'].push_back(word);
		}

		std::istringstream iss(sentence);
		string word, res;
		while (iss >> word) {
			for (auto prefix: prefixs[word[0]-'a']) {
				if (word.substr(0, prefix.size()) == prefix) {
					word = prefix;
					break;
				}
			}
			res += word + ' ';
		}
		res.pop_back();

		return res;
	}
};
