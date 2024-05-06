class Solution {
public:
    long long wonderfulSubstrings(string word) {
        vector<long long> count(1024);
        count[0] = 1;
        int mask = 0;
        long long res = 0;
        for (char c : word) {
            mask ^= 1 << (c - 'a');
            res += count[mask];
            for (int i = 0; i < 10; ++i) {
                res += count[mask ^ (1 << i)];
            }
            ++count[mask];
        }
        return res;
    }
};
