class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] <= nums[i - 1]) {
                int prev = nums[i];
                nums[i] = nums[i - 1] + 1;
                moves += nums[i] - prev;
            }
        }
        return moves;
    }
};
