class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        while(i < version1.size() || j < version2.size()) {
            long long x = 0; // use long long instead of int
            for(; i < version1.size() && version1[i] != '.'; i++) {
                if (x > INT_MAX / 10 || (x == INT_MAX / 10 && version1[i] - '0' > INT_MAX % 10)) {
                    // handle overflow
                    x = INT_MAX;
                    break;
                }
                x = x * 10 + version1[i] - '0';
            }
            i++; // Skip the dot
            
            long long y = 0; // use long long instead of int
            for(; j < version2.size() && version2[j] != '.'; j++) {
                if (y > INT_MAX / 10 || (y == INT_MAX / 10 && version2[j] - '0' > INT_MAX % 10)) {
                    // handle overflow
                    y = INT_MAX;
                    break;
                }
                y = y * 10 + version2[j] - '0';
            }
            j++; // Skip the dot
            
            if(x < y)
                return -1;
            if(x > y)
                return 1;
        }
        return 0;
    }
};
