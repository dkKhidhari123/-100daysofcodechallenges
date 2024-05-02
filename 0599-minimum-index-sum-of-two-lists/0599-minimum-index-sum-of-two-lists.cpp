class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> map;
        for (int i = 0; i < list1.size(); i++) {
            map[list1[i]] = i;
        }
        
        vector<string> result;
        int minSum = INT_MAX;
        for (int i = 0; i < list2.size(); i++) {
            if (map.count(list2[i])) {
                int sum = i + map[list2[i]];
                if (sum < minSum) {
                    result.clear();
                    result.push_back(list2[i]);
                    minSum = sum;
                } else if (sum == minSum) {
                    result.push_back(list2[i]);
                }
            }
        }
        return result;
    }
};
