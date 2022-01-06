class Solution {
public:
    int bitwiseComplement(int n) {
        short numDigits = 0;
        int comp = 0;
        do {
            comp = comp | ((1-(n&1)) << (numDigits++));
            n = n >> 1;
        } while (n > 0);
        return comp;
    }
};