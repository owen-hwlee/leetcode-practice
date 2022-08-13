class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        
        int temp = x;
        long reverse = 0;
        
        do {
            reverse *= 10;
            reverse += temp % 10;
            temp /= 10;
        } while (temp > 0);
        
        return x == reverse;
    }
};