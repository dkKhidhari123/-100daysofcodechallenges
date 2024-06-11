class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> freq;
        for(int num : arr1) freq[num]++;
        
        int i = 0;
        for(int num : arr2) {
            while(freq[num]-- > 0) {
                arr1[i++] = num;
            }
        }
        
        for(auto &[num, count] : freq) {
            while(count-- > 0) {
                arr1[i++] = num;
            }
        }
        
        return arr1;
    }
};