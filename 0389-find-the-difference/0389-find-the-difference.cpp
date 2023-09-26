class Solution {
public:
    char findTheDifference(string s, string t) {
        // use bitwise XOR on all letters in both s and t to reveal the remaining letter
        
        char x = '\0';
        
        for (char& c: s) {
            x ^= c;
        }
        for (char& c: t) {
            x ^= c;
        }
        
        return x;
    }
};