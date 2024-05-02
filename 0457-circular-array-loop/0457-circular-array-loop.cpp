class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int slow = i, fast = getNext(nums, i);
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNext(nums, fast)] > 0) {
                if (slow == fast) {
                    if (slow == getNext(nums, slow)) {
                        break;
                    }
                    return true;
                }
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }
        }
        return false;
    }

private:
    int getNext(vector<int>& nums, int i) {
        int n = nums.size();
        int next = (i + nums[i]) % n;
        return next >= 0 ? next : next + n;
    }
};
