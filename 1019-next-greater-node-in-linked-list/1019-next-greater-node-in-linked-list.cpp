/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nums;
        for (ListNode* node = head; node; node = node->next)
            nums.push_back(node->val);
        vector<int> res(nums.size());
        stack<int> s;
        for (int i = 0; i < nums.size(); i++) {
            while (!s.empty() && nums[s.top()] < nums[i]) {
                res[s.top()] = nums[i];
                s.pop();
            }
            s.push(i);
        }
        return res;
    }
};