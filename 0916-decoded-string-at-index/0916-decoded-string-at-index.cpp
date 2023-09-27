class Solution {
public:
    string decodeAtIndex(string s, int k) {
        stack<char> visitedLetters;     // stack to store all traversed letters
        unsigned long long decodedLength = 0;   // 64 bit integer to store current length to compare with k

        // calculate length of decoded string as we traverse s until length surpasses k
        for (int i = 0; i < s.size(); ++i) {
            const char& c = s[i];
            visitedLetters.push(c);
            if (c >= '2' && c <= '9') {
                // char read is a digit
                // decoded string length multiplied by digit numerical value
                int repeat = c - '0';
                decodedLength *= repeat;
            } else {
                // char read is a letter
                // decoded string length + 1
                ++decodedLength;
            }
            if (decodedLength >= k) {
                break;
            }
        }
        
        // reverse process to determine which char
        unsigned long long currentLength = decodedLength;
        int h = k;
        do {
            const char& c = visitedLetters.top();
            if (c >= '2' && c <= '9') {
                // char read is a digit
                // revert by dividing length by numerical value of digit
                int repeat = c - '0';
                currentLength /= repeat;

                // reduce k into h by finding remainder
                h %= currentLength;
                if (h == 0) h = currentLength;
            } else {
                // char read is a letter
                // revert by reducing length by 1
                if (currentLength == h) {
                    // most recently appended letter aka c is the answer
                    return string(1, c);
                }
                --currentLength;
            }
            visitedLetters.pop();
        } while (!visitedLetters.empty());

        return s.substr(0, 1);
    }
};