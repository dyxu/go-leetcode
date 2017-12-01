class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
		unordered_map<string, vector<string>> files;
		vector<vector<string>> res;
		for (string& path: paths) {
			std::stringstream ss(path);
			string root, s;
			std::getline(ss, root, ' ');
			while (std::getline(ss, s, ' ')) {
				string name = root + '/' + s.substr(0, s.find('('));
				string content = s.substr(s.find('(') + 1, s.find(')') - s.find('(') - 1);
				files[content].push_back(name);
			}
		}
		for (auto file: files) {
			if (file.second.size() > 1) {
				res.push_back(file.second);
			}
		}

		return res;
    }
};
