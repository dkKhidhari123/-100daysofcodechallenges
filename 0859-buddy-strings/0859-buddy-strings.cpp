class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        if (s == goal) {
            set<char> unique_chars(s.begin(), s.end());
            if (unique_chars.size() < s.size()) return true;
            return false;
        }
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != goal[i]) diff.push_back(i);
        }
        if (diff.size() == 2 && s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]]) return true;
        return false;
    }
};
