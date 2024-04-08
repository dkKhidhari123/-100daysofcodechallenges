class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[2] = {};
        for (int s: students)
            count[s]++;
        int k = 0;
        while (k < sandwiches.size()) {
            if (count[sandwiches[k]] > 0) {
                count[sandwiches[k]]--;
                k++;
            } else {
                break;
            }
        }
        return sandwiches.size() - k;
    }
};
