class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorResult = 0;
        for (int num : nums) {
            xorResult ^= num;
        }
        int operations = 0;
        for (int i = 0; i < 31; i++) {
            if (((xorResult >> i) & 1) != ((k >> i) & 1)) {
                operations++;
            }
        }
        return operations;
    }
};
