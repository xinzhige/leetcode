class Solution {
public:
    string simplifyPath(string path) {
        string result, current;
        vector<string> dirs;
        stringstream out(path);
        while (getline(out, current, '/')) {
            if (current == "..") {
	            if (!dirs.empty()) {
	                dirs.pop_back();
	            }
            } else if (!current.empty() && current != ".") {
	            dirs.emplace_back(current);
            }
        }
        for (auto s : dirs) {
            result += "/" + s;
        }
        return result.size() == 0 ? "/" : result;
    }
};
