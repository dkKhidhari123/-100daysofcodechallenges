class Solution {
public:
    int passThePillow(int n, int time) {
        int cycle = 2 * n - 2;
        int remainder = time % cycle;
        if (remainder < n) {
            return remainder + 1;
        }
        return cycle - remainder + 1;
    }
};
