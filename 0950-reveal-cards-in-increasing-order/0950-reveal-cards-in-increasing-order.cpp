class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end(), greater<int>());
        deque<int> dq;
        for (int& card : deck) {
            if (!dq.empty()) {
                dq.push_front(dq.back());
                dq.pop_back();
            }
            dq.push_front(card);
        }
        return vector<int>(dq.begin(), dq.end());
    }
};
