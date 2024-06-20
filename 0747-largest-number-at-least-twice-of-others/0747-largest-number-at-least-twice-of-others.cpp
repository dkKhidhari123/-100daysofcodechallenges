class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxIndex = 0;
        int maxValue = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > maxValue) {
                maxValue = nums[i];
                maxIndex = i;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (i != maxIndex && nums[i] * 2 > maxValue) {
                return -1;
            }
        }

        return maxIndex;
    }
};
