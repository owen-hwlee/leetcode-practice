class Solution {
public:
    bool isPalindrome(string s) {
        string clean_str;
        for (char c: s) {
            if (c >= 'a' && c <= 'z' || c >= '0' && c <= '9') {
                clean_str += c;
            }
            else if (c >= 'A' && c <= 'Z') {
                clean_str += c - 'A' + 'a';
            }
        }
        
        int clean_str_size = clean_str.size();
        for (int i = 0; i < clean_str_size/2; ++i) {
            if (clean_str[i] != clean_str[clean_str_size - i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};