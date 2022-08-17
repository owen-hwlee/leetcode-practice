class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) return 0;
        
        int haystackSize = haystack.size();
        int needleSize = needle.size();
        
        for (int i = 0; i <= haystackSize - needleSize; ++i) {
            if (!haystack.substr(i, needleSize).compare(needle)) {
                return i;
            }
        }
        
        return -1;
    }
};