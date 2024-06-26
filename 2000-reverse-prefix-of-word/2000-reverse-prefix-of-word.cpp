class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = word.find(ch);
        if (pos != string::npos) {
            reverse(word.begin(), word.begin() + pos + 1);
        }
        return word;
    }
};