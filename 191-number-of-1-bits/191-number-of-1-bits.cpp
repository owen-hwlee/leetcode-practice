class Solution {
public:
    int hammingWeight(uint32_t n) {
        if (n == 0) return 0;
        short count = 0;
        do {
            count += n & 1;
            n = n >> 1;
        } while (n > 0);
        return count;
    }
};