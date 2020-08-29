#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> counts;
        set<char> visited;
        std::vector<char> res;
        for (int i = 0; i < s.length(); i++) {
            counts[s[i]]++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (visited.find(s[i]) != visited.end()) {
                continue;
            }
            if (!res.empty()) {
                while (!res.empty() && s[i] < res.back() && counts[s[i]] > 0) {
                    auto iter = visited.find();
                    if (iter != visited.end()) {
                        visited.erase(iter);
                    }
                    res.pop_back();
                }
            }
            res.append(s[i]);
            visited.insert(s[i]);
        }

        return string(res.rbegin(), res.rend());
    }
};