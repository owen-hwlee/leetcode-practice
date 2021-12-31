class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // n must only contain the digit 1
        // e.g. n = 111111
        
        // n cannot be even number
        if (!(k & 1)) return -1;
        // n cannot be multiple of 5
        if (!(k % 5)) return -1;
        
        unsigned long long n = 1;
        int count = 1;
        while (n % k) {
            n = n * 10 + 1;
            ++count;
            n %= k;
        }
        return count;
    }
};