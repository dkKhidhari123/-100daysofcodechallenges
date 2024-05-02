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
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }
    
    int getRandom() {
        ListNode* node = head;
        int i = 1;
        int result = 0;
        while (node) {
            if (rand() % i == 0) {
                result = node->val;
            }
            i++;
            node = node->next;
        }
        return result;
    }
};


/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */