class Solution {
public:
    string reverseWords(string s) {
        size_t i = 0, j = 0;   // (i -> start, j -> end) of each word
        const size_t& size = s.size();

        for (size_t k = 1; k < size; ++k) {
            if (s[k] == ' ') {
                // whitespace reached, start swapping
                swap_char(s, i, j);
                // update i, j to start index of next word
                i = j = k + 1;
            } else {
                // other ascii char reached, update j
                j = k;
            }
        }
        // no trailing spaces, manually swap last word
        swap_char(s, i, j);

        return s;
    }
private:
    inline void swap_char(string& s, const size_t& i, const size_t& j) {
        size_t num_swap = (j + 1 - i) / 2;
        for (size_t k = 0; k < num_swap; ++k) {
            swap(s[i + k], s[j - k]);
        }
    }
};