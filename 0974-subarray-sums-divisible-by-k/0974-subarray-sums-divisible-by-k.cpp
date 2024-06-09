class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        count[0] = 1;
        int sum = 0, ans = 0;
        for (int num : nums) {
            sum = (sum + num % k + k) % k;
            ans += count[sum]++;
        }
        return ans;
    }
};
