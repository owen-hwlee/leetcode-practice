class Solution {
public:
    string reverseWords(string s) {
        size_t start = 0;   // start index of each word
        const size_t& size = s.size();

        for (size_t i = 1; i < size; ++i) {
            if (s[i] == ' ' || i == size - 1) {
                // whitespace or end of string reached, start swapping
                size_t end = (i != size - 1) ? i - 1 : i;
                size_t num_swap = (end + 1 - start) / 2;
                for (size_t j = 0; j < num_swap; ++j) {
                    swap(s[start + j], s[end - j]);
                }

                start = i + 1;  // update start to index of next word
            }
        }

        return s;
    }
};