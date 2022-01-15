class Solution {
public:
    int myAtoi(string s) {
        int idx = 0;
        long num = 0;
        bool positive = true;
        // skip leading whitespace
        // !(valid_char(s[idx]) || s[idx] == '+' || s[idx] == '-')
        while (idx < s.size() && s[idx] == ' ') {
            ++idx;
        }
        // check positive or negative
        if (s[idx] == '-') {
            positive = false;
            ++idx;
        } else if (s[idx] == '+') {
            ++idx;
        }
        // convert to number
        while (idx < s.size() && s[idx] >= '0' && s[idx] <= '9') {
            num *= 10; num -= (s[idx] - '0');
            // clamp integer
            if (num <= INT_MIN) {
                return (positive ? INT_MAX : INT_MIN);
            }
            ++idx;
        }
        return (positive ? -num : num);
    }
};